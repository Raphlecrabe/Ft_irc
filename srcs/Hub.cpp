#include "../incs/Hub.hpp"
#include "../incs/User.hpp"
#include <iostream>
#include <map>
#include <vector>
#include "../incs/Server.hpp"

Hub::Hub(Server *server) : _server(server) {
	this->_messageOfTheDay = NULL;

	setMessageOfTheDay("This is the message of the day!");
}

Hub::~Hub() {
	if (_users.size() == 0)
		return;

	std::vector<User *>::iterator it;

	for (it = _users.begin(); it != _users.end(); it++)
		delete (*it);

	_users.clear();

	delete _messageOfTheDay;
}

User & Hub::CreateUser(int fd) {
	User * new_user = new User(fd);

	_users.push_back(new_user);

	return *new_user;
}

void Hub::RemoveUserByFd(int fd) {
	
	std::vector<User *>::iterator it = findUserByFd(fd);

	if (it != _users.end())
		_users.erase(it);
}

User * Hub::getUserByFd(int fd) {
	std::vector<User *>::iterator it = findUserByFd(fd);

	if (it != _users.end())
		return *(it);
	
	return NULL;
}

std::vector<User *>::iterator Hub::findUserByFd(int fd) {
	if (_users.size() == 0)
		return _users.end();

	std::vector<User*>::iterator it;
	
	for (it = _users.begin(); it != _users.end(); it++)
	{
		if ((*it)->getFd() == fd)
			break;
	}

	return it;
}

std::vector<User *> const & Hub::getUserList() const {
	return _users;
}

std::string const &Hub::getServerName() const { return _server->getServerName(); }
std::string const &Hub::getNetworkName() const { return _server->getNetworkName(); }
std::string	const &Hub::getStartTime() const { return _server->getStartTime(); }
std::string const *Hub::getMessageOfTheDay() const { return this->_messageOfTheDay; }

void		Hub::setMessageOfTheDay(std::string s) {
	_messageOfTheDay = new std::string(s);
}

Channel	&Hub::CreateChannel(std::string &name, User *user)
{	
	if (user->getNumberOfChannels() == CHANNEL_LIMIT)
		throw Hub::TooManyChannels();
	if (_numberofchannels == CHANNEL_MAX)
		throw Hub::ChannelMaxReached();
	for (unsigned int i = 0; i < name.size(); i++)
	{
		if (isalnum(name[i]) == 0)
		{
			throw Hub::BadChannelName();
		}
	}
	Channel	*newchannel = new Channel(name);
	if (newchannel->AddUser(user) == -1)
		throw Hub::ChannelIsFull();
	newchannel->AddFd(user->getFd());
	user->AddChannel(newchannel);
	_channels.push_back(newchannel);
	_numberofchannels ++;
	return *newchannel;
}

Channel	*Hub::getChannelByName(std::string &name) const
{
	std::vector<Channel*>::const_iterator	it;

	if (_channels.size() == 0)
		return (NULL);
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->get_name() == name)
		{
			return (*it);
		}
	}
	return (NULL);
}

void	Hub::removeChannelByName(std::string name)
{
	//TO DO : A coder lol 
	(void)name;
}

std::vector<Channel *> const &Hub::getChannelList() const
{
	return (_channels);
}

int	Hub::getNumberOfChannels() const
{
	return (_numberofchannels);
}
