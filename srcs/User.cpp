#include "../incs/User.hpp"

#include <iostream>

User::User(int fd) : _fd(fd), _isAuth(false) { }

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

void User::setAuth() { _isAuth = true; }
bool User::isAuth() { return _isAuth; }

void User::AddChannel(Channel *channel)
{
	_number_of_channels ++;
	_channels.push_back(channel);
}

void User::RemoveItselfFromChannels() {
	if (_channels.size() == 0)
		return;

	std::vector<Channel *>::iterator it;

	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		(*it)->RemoveUser(*this);
	}
	
	_channels.clear();
}

Message User::getQuitMessage(std::string reason)
{
	Message newmessage(this->_nickname, "QUIT", reason);

	if (_channels.size() == 0)
		return newmessage;

	std::vector<Channel *>::iterator it;

	for (it = this->_channels.begin(); it != this->_channels.end(); it++)
	{
		Debug::Log << "User: getQuitMessage: adding destinators from channel " << (*it)->get_name() << std::endl;
		(*it)->addDestinatorsExceptOneInMessage(this, newmessage);
	}

	return newmessage;
}

bool 	User::NicknameIsSet() { return _nickname != ""; }