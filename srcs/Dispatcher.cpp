/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:52:35 by raphael           #+#    #+#             */
/*   Updated: 2022/11/29 17:13:09 by fbelthoi         ###   ########.fr       */
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
	this->_Replyer.TreatReplys(request, client_request);
	this->_Messager.TreatMessages(request);

	return 0;
}