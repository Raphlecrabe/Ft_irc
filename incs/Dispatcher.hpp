/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:20 by raphael           #+#    #+#             */
/*   Updated: 2022/11/17 17:11:05 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_HPP
# define DISPATCHER_HPP

# include "/ACommand/ACommand.hpp"

class Dispatcher
{
private:
	std::map<string, ACommand>	_Commands;
	Replyer					_Replyer;
	Messager				_Messager:
	CommandCreator			_CommandCreator;
public:
	Dispatcher();
	~Dispatcher();

	void	Execute(Message	client_request);

};

Dispatcher::Dispatcher()
{
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
		//Que faire quand on connait pas la commande ?
		//Faudra déjà supprimer la truc ajouté dans la map
		//Et ensuite envoyer un message au serveur ?
	}
	else
	{
		CallBack	*request = Command.cmd_execute(client_request, hub);
		this->Replyer.TreatReplys(request->_Replys, hub);
		this->_Messager.TreatMessages(request->_Messages, hub);
	}
}

#endif