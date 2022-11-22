#include "../incs/User.hpp"

User::User(int fd) : _fd(fd) {

}

User::~User() {
	
}

const int & User::getFd() { return this->_fd; }