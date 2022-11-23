/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:44:20 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/23 14:18:39 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ACommand/ACommand.hpp"
#include "../../incs/ACommand/Nick.hpp"
#include "../../incs/Callback.hpp"

Nick::Nick() : ACommand("NICK") {
	
}

Nick::~Nick() {
	
}

Callback	*Nick::cmdExecute(Message & message, Hub & hub)
{
	std::string nickname = message.getParams();

	if (check_nick(nickname, hub) == -1)
		return new Callback();

	message.getSender().setNickname(nickname);

	return new Callback();
}

int	Nick::check_nick(std::string nickname, Hub & hub)
{
	if (empty_nick(nickname) == -1)
	{
		return (-1);
	}
	if (wrong_nick(nickname) == -1)
	{
		return (-1);
	}
	if (used_nick(nickname, hub) == -1)
	{
		return (-1);
	}

	return 0;
}

int	Nick::used_nick(std::string nickname, Hub hub)
{
	std::vector<User *> _userlist = hub.getUserList();

	if (_userlist.size() == 0)
		return 0;

	std::vector<User *>::iterator it;

	for (it = _userlist.begin(); it != _userlist.end(); it++)
	{
		if ((*it)->getNickname() == nickname)
		{
			return (-1);
		}
	}
	return (0);
}

int	Nick::wrong_nick(std::string nickname)
{
	int size = nickname.size();

	for (int i = 0; i < size; i++)
	{
		if (std::isalnum(nickname[i]) == 0)
		{
			return (-1);
		}
	}
	return (0);
}

int	Nick::empty_nick(std::string nickname)
{
	if (nickname.empty() == 1)
	{
		return (-1);
	}
	return (0);
}