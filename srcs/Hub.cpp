#include "../incs/Hub.hpp"
#include "../incs/User.hpp"
#include <iostream>
#include <map>

Hub::Hub() {

}

Hub::~Hub() {
	
}

User & Hub::CreateUser(int fd) {
	User * new_user = new User(fd);

	std::pair<int, User *> pair(fd, new_user);

	_users.insert(pair);

	return *new_user;
}

void Hub::RemoveUserByFd(int fd) {
	std::map<int, User*>::iterator it;
	
	it = _users.find(fd);

	if (it != _users.end())
		_users.erase(it);
}