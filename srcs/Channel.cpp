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

Channel::Channel(std::string &name) : _name(name) 
{
	_client_limit = CHANNEL_USER_LIMIT;
}

Channel::~Channel() 
{

}

void Channel::AddFd(int fd)
{
	_users_fd.push_back(fd);
}

int	Channel::AddUser(User *new_user)
{
	std::cout << "lol0" << std::endl;
	if (static_cast<int>(_users.size()) == _client_limit)
	{
		Debug::Log("Max user channel hit");
		return (-1);
	}
	std::cout << "lol1" << std::endl;
	_users.push_back(new_user);
	std::cout << "lol2" << std::endl;
	this->AddFd(new_user->getFd());
	return (0);
}

int	Channel::RemoveUser(User &old_user)
{
	std::vector<User *>::iterator	it;
	std::vector<int>::iterator	it2;

	it2 = _users_fd.begin();

	for(it = _users.begin(); it != _users.end(); it++)
	{
		if ((*it)->getFd() == old_user.getFd())
		{
			_users.erase(it);
			_users_fd.erase(it2);
			break;
		}
		it2++;
	}
	if (this->get_users().size() == 0)
		return (-1);
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

void	Channel::ChangeTopic(std::string name)
{
	_topic = name;
}

void	Channel::addDestinatorsExceptOneInMessage(User *user, Message &message)
{
	std::vector<User *>	users = this->get_users();
	std::vector<User *>::iterator	it;

	if (users.size() == 0)
		return ;

	for (it = users.begin(); it != users.end(); it++)
	{
		if ((*it)->getName() != user->getName())
		{
			message.addDestinator(*it);
		}
	}
}

int	Channel::UserIsInChannel(User *user)
{
	if (_users.size() == 0)
		return (0);
	std::vector<User *>::iterator	it;
	for (it = _users.begin(); it !=  _users.end(); it++)
	{
		if ((*it)->getName() == user->getName())
			return (1);
	}
	return (0);
}