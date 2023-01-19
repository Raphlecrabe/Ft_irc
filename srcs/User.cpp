#include "../incs/User.hpp"

#include <iostream>

User::User(int fd) : _fd(fd), _isAuth(false), _isRegistered(false) { }

User::~User() {	}

const int & User::getFd() { return this->_fd; }

const std::string & User::getNickname() const { return this->_nickname; }
const std::string & User::getName() const { return this->_name; }
const std::string & User::getRealname() const { return this->_realname; }
int			User::getNumberOfChannels() const { return (_number_of_channels); }
const std::vector<Channel *> & User::getChannels() const {return _channels; }
bool		User::IsRegistered() { return this->_isRegistered; }
void 		User::Register() { this->_isRegistered = true; }

void User::setNickname(std::string const & nickname) {
	this->_nickname = nickname;
}

void User::setName(std::string const & name) { this->_name = name; }
void User::setRealname(std::string const & realname) { this->_realname = realname; }
void User::setNumberOfChannels(int number) { this->_number_of_channels = number; }

void User::setAuth(bool a) { _isAuth = a; }
bool User::isAuth() { return _isAuth; }

void User::AddChannel(Channel *channel)
{
	_number_of_channels ++;
	_channels.push_back(channel);
}

void User::RemoveChannel(Channel *channel)
{
	std::vector<Channel *>::iterator it;
	if (channel == NULL)
		return ;
	it = find(this->_channels.begin(), this->_channels.end(), channel);
	if (it == _channels.end())
		return ;
	_channels.erase(it);
}

void User::RemoveItselfFromChannels(Hub &hub) {
	if (_channels.size() == 0)
		return;

	std::vector<Channel *>::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		(*it)->removeChannelOperator(this);
		if ((*it)->RemoveUser(*this) == -1)
			hub.removeChannelByName((*it)->get_name());
	}
	_channels.clear();
}

Message User::getQuitMessage(std::string reason)
{
	Message newmessage(this->_nickname, "QUIT", reason);

	this->addAllConnectedUsersToMessage(newmessage);

	newmessage.addDestinator(this);

	return newmessage;
}

void	User::addAllConnectedUsersToMessage(Message & message) {
	if (_channels.size() == 0)
		return;

	std::vector<Channel *>::iterator it;

	for (it = this->_channels.begin(); it != this->_channels.end(); it++)
	{
		Debug::Log << "User: addAllUsersToMessage: adding destinators from channel " << (*it)->get_name() << std::endl;
		(*it)->addDestinatorsExceptOneInMessage(this, message);
	}
}

bool 	User::NicknameIsSet() { return _nickname != ""; }