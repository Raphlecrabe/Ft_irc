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
	
	if (_users.size() == 0)
		return;

	std::vector<User*>::iterator it;
	
	for (it = _users.begin(); it != _users.end(); it++)
	{
		if ((*it)->getFd() == fd)
			_users.erase(it);
	}
}

std::vector<User *> const & Hub::getUserList() const {
	return _users;
}