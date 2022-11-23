#include "../incs/User.hpp"

#include <iostream>

User::User(int fd) : _fd(fd) { }

User::~User() {	}

const int & User::getFd() { return this->_fd; }

const std::string & User::getNickname() const { return this->_nickname; }
const std::string & User::getName() const { return this->_name; }
const std::string & User::getRealname() const { return this->_realname; }

void User::setNickname(std::string & nickname) {

	this->_nickname = nickname;
}

void User::setName(std::string & name) { this->_name = name; }
void User::setRealname(std::string & realname) { this->_realname = realname; }