/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:20 by raphael           #+#    #+#             */
/*   Updated: 2022/11/17 15:58:11 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_HPP
# define DISPATCHER_HPP

# include "/ACommand/ACommand.hpp"

class Dispatcher
{
private:
	map<string, ACommand>	_Commands;

public:
	Dispatcher();
	~Dispatcher();

	void	execute(Message	client_request);

};

Dispatcher::Dispatcher()
{
}

Dispatcher::~Dispatcher()
{
}

CallBack	Dispatcher::execute(Message client_request, Hub hub)
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
		CallBack	*resquest = Command.cmd_execute(client_request, hub);
		
	}
}

#endif