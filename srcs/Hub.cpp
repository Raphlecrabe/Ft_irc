#include "../incs/Hub.hpp"
#include "../incs/User.hpp"
#include <iostream>
#include <map>
#include <vector>
#include "../incs/Server.hpp"

Hub::Hub(Server *server) : _server(server) {
	this->_messageOfTheDay = NULL;

	std::pair<std::string, std::string> config;
	config.first = "rafymonach";
	config.second = "mdpraf";
	_operatorConfig.insert(config);
	config.first = "fbelthoi";
	config.second = "mdp";
	_operatorConfig.insert(config);
	
	setMessageOfTheDay("This is the message of the day!");
}

Hub::~Hub() {
	if (_users.size() == 0)
		return;

	std::vector<User *>::iterator it;

	for (it = _users.begin(); it != _users.end(); it++)
		delete (*it);

	_users.clear();

	std::vector<Channel *>::iterator itc;

	for (itc = _channels.begin(); itc != _channels.end(); itc++)
		delete (*itc);

	_channels.clear();

	delete _messageOfTheDay;
}

User & Hub::CreateUser(int fd) {
	User * new_user = new User(fd);

	_users.push_back(new_user);

	return *new_user;
}

void Hub::RemoveUserByFd(int fd) {

	Debug::Log << "Hub: Removing User from UserList..." << std::endl;

	std::vector<User *>::iterator it = findUserByFd(fd);

	if (it == _users.end())
		return;

	User *user = *it;

	if (it != _users.end())
		_users.erase(it);

	if (isIrcOperator(user))
	{
		Debug::Log << "Hub: Removing User from ircOperators..." << std::endl;

		for (it = _ircOperators.begin(); it != _ircOperators.end(); it++)
		{
			if ((*it)->getFd() == fd)
			{
				_ircOperators.erase(it);
				break;
			}
		}
	}

	Debug::Log << "Hub: Removing User from Channels..." << std::endl;

	user->RemoveItselfFromChannels();

	Debug::Log << "Deleting User..." << std::endl;

	delete user;
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

User *Hub::get_UserByNickName(std::string nickname)
{
	for (unsigned int i = 0; i < _users.size(); i++)
	{
		if (_users[i]->getNickname() == nickname)
			return (_users[i]);
	}
	return (NULL);
}

std::vector<User *> const & Hub::getUserList() const {
	return _users;
}

std::string const &Hub::getServerPassword() const { return _server->getServerPassword(); }
std::string const &Hub::getServerName() const { return _server->getServerName(); }
std::string const &Hub::getNetworkName() const { return _server->getNetworkName(); }
std::string	const &Hub::getStartTime() const { return _server->getStartTime(); }
std::string const *Hub::getMessageOfTheDay() const { return this->_messageOfTheDay; }

void		Hub::setMessageOfTheDay(std::string s) {
	_messageOfTheDay = new std::string(s);
}

bool	Hub::chanNameIsValid(std::string const & name)
{
	if (name[0] != '#')
		return false;

	for (unsigned int i = 1; i < name.size(); i++) {
		if (name[i] == ' ' || name[i] == ',') // MUST CHECK FOR '^G' char
			return false;
	}

	return true;
}

Channel	&Hub::CreateChannel(std::string &name, User *user)
{
	if (user->getNumberOfChannels() == CHANNEL_LIMIT)
		throw Hub::TooManyChannels();
	if (_numberofchannels == CHANNEL_MAX)
		throw Hub::ChannelMaxReached();
	if (chanNameIsValid(name) == false)
		throw Hub::BadChannelName();
	Channel	*newchannel = new Channel(name);
	if (newchannel->AddUser(user) == -1)
		throw Hub::ChannelIsFull();
	_channels.push_back(newchannel);
	_numberofchannels ++;
	return *newchannel;
}

Channel	*Hub::getChannelByName(std::string const &name) const
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

void	Hub::removeChannelByName(std::string const & name)
{
	std::vector<Channel *>::iterator findChannel;
	for (findChannel = _channels.begin(); findChannel != _channels.end(); findChannel++)
	{
		if ((*findChannel)->get_name() == name)
		{
			_channels.erase(findChannel);
			break;
		}
	}
}

std::vector<Channel *> const &Hub::getChannelList() const
{
	return (_channels);
}

int	Hub::getNumberOfChannels() const
{
	return (_numberofchannels);
}


int	Hub::isIrcOperator(User *user)
{
	for(unsigned int i = 0; i < _ircOperators.size(); i++)
	{
		if (_ircOperators[i]->getNickname() == user->getNickname())
			return (1);
	}
	return (0);
}

void	Hub::addIrcOperator(User *user)
{
	if (this->isIrcOperator(user) == 1)
		return ;
	_ircOperators.push_back(user);
}

int		Hub::isInConfig(std::string name, std::string password)
{
	std::map<std::string, std::string>::iterator it;

	it = _operatorConfig.find(name);
	if (it == _operatorConfig.end())
		return (0);
	if (it->second == password)
		return (1);
	return (0);
}

void	Hub::program_to_close(int fd) {
	_server->program_to_close(fd);
}