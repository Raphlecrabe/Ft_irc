#include "../incs/User.hpp"

#include <iostream>

User::User(int fd) : _fd(fd) { }

User::~User() {	}

const int & User::getFd() { return this->_fd; }

const std::string & User::getNickname() const { return this->_nickname; }
const std::string & User::getName() const { return this->_name; }
const std::string & User::getRealname() const { return this->_realname; }
int			User::getNumberOfChannels() const { return (_number_of_channels); }
const std::vector<Channel *> & User::getChannels() const {return _channels; }

void User::setNickname(std::string & nickname) {
	if (nickname.size() > NICKLEN)
	{
		std::string troncnick;
		for (int i = 0; i < NICKLEN; i++)
		{
			troncnick.push_back(nickname[i]);
		}
		this->_nickname = troncnick;
		return ;
	}
	this->_nickname = nickname;
}

void User::setName(std::string & name) { this->_name = name; }
void User::setRealname(std::string & realname) { this->_realname = realname; }
void User::setNumberOfChannels(int number) { this->_number_of_channels = number; }

void User::AddChannel(Channel *channel)
{
	_number_of_channels ++;
	_channels.push_back(channel);
}