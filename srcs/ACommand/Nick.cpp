/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:44:20 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/22 15:45:01 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ACommand/Nick.hpp"

Nick::~Nick()
{
}

Callback	*Nick::getmsg(Message message, Hub hub)
{
}

int	Nick::check_nick(std::string nickname, Hub hub)
{
	if (empty_nick(nickname) == -1)
	{
		return (-1);
	}
	if (wrong_nick(nickname) == -1)
	{
		return (-1);
	}
	if (used_nick(nickname) == -1)
	{
		return (-1);
	}
}

int	Nick::used_nick(std::string nickname, Hub hub)
{
	std::vector<User>::iterator	it;

	for (it = hub._server_users.begin(); it != hub._server_users.end(); it++)
	{
		if (*it._nickname == nickname)
		{
			return (-1);
		}
	}
	return (0);
}

int	Nick::wrong_nick(std::string nickname)
{
	for (int i = 0; i < nickname.size(); i++)
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