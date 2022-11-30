/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:52:35 by raphael           #+#    #+#             */
/*   Updated: 2022/11/30 13:54:08 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

	ACommand	*Command = this->_CommandCreator.getCommandByName(cmdname);

	if (Command == NULL)
	{
		//Que faire quand on connait pas la commande ?
		//Et ensuite envoyer un message au serveur ?
		std::cout << "Command not found: " << cmdname << std::endl;
		return (-1);
	}

	Callback	&request = Command->cmdExecute(client_request, _hub);
	//std::cout << "command executed: " << cmdname << " with result of " << client_request.getSender().getNickname() << std::endl;
	this->_Replyer.TreatReplys(request, client_request);
	this->_Messager.TreatMessages(request);

	return 0;
}