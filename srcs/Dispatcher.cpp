/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:52:35 by raphael           #+#    #+#             */
/*   Updated: 2022/12/12 15:41:34 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Debug.hpp"
#include "../incs/Callback.hpp"
#include "../incs/Dispatcher.hpp"

Dispatcher::Dispatcher(Hub & hub) : _hub(hub), _Replyer(hub) {
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
		Debug::Log(std::string("Dispatcher: Command not found: ") + std::string(cmdname));
		return (-1);
	}

	Debug::Log(std::string("Dispatcher: executing commmand ") + std::string(cmdname));
	
	Callback	&request = Command->cmdExecute(client_request, _hub);
	this->_Replyer.TreatReplys(request, client_request);
	this->_Messager.TreatMessages(request);
	this->TreatCommands(request, client_request.getSender());
	return 0;
}

int	Dispatcher::TreatCommands(Callback &callback, User *sender) {
	std::vector<std::string> commands = callback.getCommands();

	std::vector<std::string>::const_iterator it;

	for (it = commands.cbegin(); it < commands.cend(); it++) {
		Message message(sender, *it);
		Execute(message);
	}

	return 0;
}