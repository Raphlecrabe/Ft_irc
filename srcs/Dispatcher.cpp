/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:52:35 by raphael           #+#    #+#             */
/*   Updated: 2022/11/23 14:43:34 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Callback.hpp"
#include "../incs/Dispatcher.hpp"

Dispatcher::Dispatcher(Hub & hub) : _hub(hub) {
}

Dispatcher::~Dispatcher()
{
}

int	Dispatcher::Execute(Message & client_request)
{
	std::string cmdname = client_request.getCommand();

	ACommand	*Command = this->_CommandCreator.getCommandByName(cmdname);

	if (Command == NULL)
	{
		//Que faire quand on connait pas la commande ?
		//Et ensuite envoyer un message au serveur ?
		return (-1);
	}

	Callback	*request = Command->cmdExecute(client_request, _hub);
	(void)request;
	std::cout << "command executed: " << cmdname << " with result of " << client_request.getSender().getNickname() << std::endl;
	//this->_Replyer.TreatReplys(request->getReplys());
	//this->_Messager.TreatMessages(request->getMessages());

	return 0;
}