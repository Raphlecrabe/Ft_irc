/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:52:35 by raphael           #+#    #+#             */
/*   Updated: 2023/01/16 10:45:30 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Debug.hpp"
#include "../incs/Callback.hpp"
#include "../incs/Dispatcher.hpp"

Dispatcher::Dispatcher(Sender &sender, Hub & hub) : _hub(hub), _Replyer(sender, hub), _Messager(sender) {
}

Dispatcher::~Dispatcher()
{
	
}

void Dispatcher::PutUserCommandOnHold(User *user, Message &message)
{
	Debug::Log << "Dispatcher: Putting message on hold from fd " << user->getFd() << std::endl;

	if (HasUserCommandOnHold(user))
	{
		on_hold[user] = message;
		return;
	}

	std::pair<User *, Message> newpair = std::make_pair(user, message);
	on_hold.insert(newpair);
}

bool Dispatcher::HasUserCommandOnHold(User *user) {
	if (on_hold.size() == 0)
		return false;

	std::map<User *, Message>::iterator it = on_hold.find(user);

	if (it != on_hold.end())
		return true;
	return false;
}

bool	Dispatcher::HoldConnectionProtocol(std::string const & cmdname, Message & client_request) {

	User *sender = client_request.getSender();

	if (cmdname == "USER" && sender->NicknameIsSet() == false)
	{
		if (sender->isAuth())
			PutUserCommandOnHold(client_request.getSender(), client_request);
		return true;
	} else if (cmdname == "NICK" && HasUserCommandOnHold(sender))
	{
		std::map<User *, Message>::iterator it = on_hold.find(sender);

		Execute(cmdname, client_request);

		Message userMsg = it->second;

		on_hold.erase(it);

		Debug::Log << "Dispatcher: Executing holded command" << std::endl;

		Execute(userMsg);
		
		return true;
	}

	return false;
}

int	Dispatcher::Execute(Message & client_request)
{
	std::string cmdname = client_request.getCommand();

	if (HoldConnectionProtocol(cmdname, client_request))
		return 0;

	return Execute(cmdname, client_request);
}

int	Dispatcher::Execute(std::string const &cmdname, Message & client_request) {
	ACommand	*Command = this->_CommandCreator.getCommandByName(cmdname);

	if (Command == NULL)
	{
		//Que faire quand on connait pas la commande ?
		//Et ensuite envoyer un message au serveur ?
		Debug::Log << "Dispatcher: Command not found: " << cmdname << std::endl;
		return 0;
	}

	Debug::Log << "Dispatcher: executing commmand " << cmdname << std::endl;
	
	Callback	&request = Command->cmdExecute(client_request, _hub);
	this->_Replyer.TreatReplys(request, client_request);
	this->_Messager.TreatMessages(request);
	this->TreatCommands(request, client_request.getSender());
	
	if (request.askForStop())
	{
		request.setStop(false);
		return -1;
	}

	return 0;
}

int	Dispatcher::TreatCommands(Callback &callback, User *sender) {
	std::vector<std::string> commands = callback.getCommands();

	std::vector<std::string>::const_iterator it;

	for (it = commands.begin(); it < commands.end(); it++) {
		Message message(sender, *it);
		Execute(message);
	}

	return 0;
}