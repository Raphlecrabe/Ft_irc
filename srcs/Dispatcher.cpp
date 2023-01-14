/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:52:35 by raphael           #+#    #+#             */
/*   Updated: 2023/01/14 19:57:38 by marvin           ###   ########.fr       */
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

int	Dispatcher::Execute(Message & client_request)
{
	std::string cmdname = client_request.getCommand();

	Execute(cmdname, client_request);
	
	return 0;
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
	
	if (request.getError())
	{
		_hub.RemoveUserByFd(client_request.getSender()->getFd());
		//_hub.close_connection(client_request.getSender()->getFd());
		request.setError(false);
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