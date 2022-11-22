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
	if (_users.size() == _client_limit)
	{
		return (-1);
	}
	_users.push_back(new_user);
	this->AddFd(new_user._socket_fd);
}

int	Channel::RemoveUser(User &old_user)
{
	std::vector<User &>::iterator	it;
	for(it = _users.begin(); it != _users.end(); it++)
	{
		if ()
	}
}

std::string	Channel::get_name()
{
	return (_name);
}

std::string	Channel::get_topic()
{
	return (_topic);
}

std::vector<User &>	Channel::get_users()
{
	return (_users);
}

std::vector<int>	Channel::get_users_fd()
{
	return (_users_fd);
}