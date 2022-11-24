/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:01:38 by raphael           #+#    #+#             */
/*   Updated: 2022/11/18 16:01:38 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Channel.hpp"

Channel::Channel() 
{
	_client_limit = CHANNEL_LIMIT;
}

Channel::~Channel() 
{

}

void Channel::AddFd(int fd)
{
	_users_fd.push_back(fd);
}

int	Channel::AddUser(User &new_user)
{
	if (static_cast<int>(_users.size()) == _client_limit)
	{
		return (-1);
	}
	_users.push_back(&new_user);
	this->AddFd(new_user.getFd());
	return (0);
}

int	Channel::RemoveUser(User &old_user)
{
	std::vector<User *>::iterator	it;
	for(it = _users.begin(); it != _users.end(); it++)
	{
		if ((*it)->getFd() == old_user.getFd())
		{
			_users.erase(it);
			break;
		}
	}
	return (0);
}

std::string	const	&Channel::get_name() const
{
	return (_name);
}

std::string	const	&Channel::get_topic() const
{
	return (_topic);
}

std::vector<User *>	const	&Channel::get_users() const
{
	return (_users);
}

std::vector<int>	const	&Channel::get_users_fd() const
{
	return (_users_fd);
}