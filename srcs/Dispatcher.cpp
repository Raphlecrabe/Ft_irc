/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:52:35 by raphael           #+#    #+#             */
/*   Updated: 2022/11/18 15:10:34 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dispatcher.hpp"

Dispatcher::Dispatcher()
{
	_Commands = _CommandCreator.CreateCommands();
}

Dispatcher::~Dispatcher()
{
}

CallBack	Dispatcher::Execute(Message client_request, Hub hub)
{
	int	map_size = this->_Commands.size();

	ACommand	Command = this->_Commands[client_request.get_command()];

	if (map_size != _Commands.size())
	{
		_Commands.erase(client_request.get_command());
		//Que faire quand on connait pas la commande ?
		//Et ensuite envoyer un message au serveur ?
		return (-1);
	}
	else
	{
		CallBack	*request = Command.cmd_execute(client_request, hub);
		this->Replyer.TreatReplys(request->getReplys(), hub);
		this->_Messager.TreatMessages(request->getMessages(), hub);
	}
}