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
	Debug::Log << "Channel " << this->get_name() << ": adding user: " << new_user->getNickname() << std::endl;
	if ((_modes.find('l') != _modes.end()) &&
		static_cast<int>(_users.size()) == _client_limit)
	{
		Debug::Log << "Max user channel hit" << std::endl;
		return (-1);
	}
	if (this->UserIsInChannel(new_user) == 1)
		return (0);
	_users.push_back(new_user);
	if (_users.size() == 1)
		_channelOperators.push_back(new_user);
	this->AddFd(new_user->getFd());
	new_user->AddChannel(this);
	return (0);
}

int	Channel::RemoveUser(User &old_user)
{
	if (_users.size() == 0)
		return 0;

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
		if ((*it) != user)
		{
			message.addDestinator(*it);
		}
	}
}

void	Channel::addAllUsersToMessage(Message &message)
{
	std::vector<User *>::iterator	it;

	if (_users.size() == 0)
		return;

	for (it = _users.begin(); it != _users.end(); it++)
	{
		Debug::Log << "Channel: addAllUsersToMessage: adding Destinator: " << (*it)->getNickname() << std::endl;
		message.addDestinator(*it);
	}
}

int	Channel::UserIsInChannel(User *user)
{
	if (_users.size() == 0)
		return (0);
	std::vector<User *>::iterator	it;
	for (it = _users.begin(); it != _users.end(); it++)
	{
		if ((*it)->getNickname() == user->getNickname())
			return (1);
	}

	return (0);
}

void Channel::SetClientLimit(int limit) {

	_client_limit = limit;
	Debug::Log << "New client limit : " << _client_limit << std::endl;
	if (_modes.find('l') == _modes.end())
	{
		std::pair<char, std::string> newmode = std::make_pair<char, std::string>('l', Utils::toString(limit));
		_modes.insert(newmode);
	}
	else
		_modes['l'] = Utils::toString(limit);

}

void Channel::RemoveClientLimit() {
	Debug::Log << "Removing client limit channel" << std::endl;
	
	std::map<char, std::string>::iterator it;

	for (it = _modes.begin(); it != _modes.end(); it++)
	{
		if (it->first == 'l')
		{
			_modes.erase(it);
			break;
		}
	}
}

std::string const Channel::getModestring() {
	if (_modes.empty())
		return "";
	
	std::string modestring = "";

	std::map<char, std::string>::iterator it;

	for (it = _modes.begin(); it != _modes.end(); it++)
		modestring += it->first;

	return modestring;
}

std::string const Channel::getModearguments() {
	if (_modes.empty())
		return "";
	
	std::string modearguments = "";

	std::map<char, std::string>::iterator it;

	for (it = _modes.begin(); it != _modes.end(); it++)
		modearguments += it->second + " ";

	if (modearguments.empty() == false)
		modearguments = modearguments.substr(0, modearguments.length() - 1);

	return modearguments;
}

int		Channel::isChannelOperator(User *user)
{
	for (unsigned int i = 0; i < _channelOperators.size(); i++)
	{
		if (user->getNickname() == _channelOperators[i]->getNickname())
			return (1);
	}
	return (0);
}

void	Channel::addChannelOperator(User *user)
{
	if (this->isChannelOperator(user) == 1)
		return ;
	_channelOperators.push_back(user);
}

std::vector<User *> const &Channel::getOperators() const
{
	return (_channelOperators);
}

void	Channel::removeChannelOperator(User *user)
{
	if (this->isChannelOperator(user) == 0)
		return;

	std::vector<User *>::iterator it;
	std::vector<User *>::iterator itend = _channelOperators.end();

	for (it = _channelOperators.begin(); it != itend; it++)
	{
		if (user->getNickname() == (*it)->getNickname())
		{
			_channelOperators.erase(it);
			break;
		}
	}
}