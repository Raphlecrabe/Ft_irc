#include "../incs/Hub.hpp"
#include "../incs/User.hpp"
#include <iostream>
#include <map>
#include <vector>

Hub::Hub() {

}

Hub::~Hub() {
	if (_users.size() == 0)
		return;

	std::vector<User *>::iterator it;

	for (it = _users.begin(); it != _users.end(); it++)
		delete (*it);

	_users.clear();
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