#include "../incs/Debug.hpp"
#include "../incs/Sender.hpp"
#include "../incs/Message.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <errno.h>
#include <sstream>

#include <sys/types.h>
#include <sys/socket.h>

Sender::Sender() {

}

Sender::~Sender() {
	
}

bool Sender::HasSomethingToSayTo(int fd) {
	if (_buffers.count(fd) == 0 || _buffers[fd] == "")
		return false;
	return true;
}

void Sender::Speak(int fd) {

	if (HasSomethingToSayTo(fd) == false)
		return;

	int sent = _send(fd, _buffers[fd]);

	if (sent == -1)
		return;

	_buffers[fd] = _buffers[fd].substr(sent);
}

int Sender::_send(int fd, std::string msg) {

	int 			res;

	unsigned int	size = msg.size();
	const char* 	datas = msg.c_str();

	res = send(fd, datas, size, 0);
	Debug::Log << "Sender: sent " << res << " bytes to fd: " << fd << ": " << msg.substr(0, res);

	if (res == -1)
	{
		Debug::Log << "Sender: Error sending datas" << std::endl;
		return -1;
	}

	return res;
}

void Sender::sendto(int fd, const char *datas, int size) {
	//Stays only for compatibility
	(void)size;
	sendto(fd, std::string(datas));

	return;
}

void Sender::sendto(int fd, std::string msg) {

	if (_buffers.count(fd) == 0) {
		std::pair<int, std::string > newpair(fd, "");
		_buffers.insert(newpair);
	}

	_buffers[fd] += msg;
}

void Sender::sendto(Message const & msg) {

	std::vector<User *> const destinators = msg.getDestinators();
	
	if (destinators.size() == 0)
	{
		Debug::Log << "Sender: no destinator specified" << std::endl;
		return;
	}

	std::vector<User *>::const_iterator it;

	for (it = destinators.begin(); it != destinators.end(); it++)
	{
		int	destfd = (*it)->getFd();
		std::string str = msg.Format();
		Debug::Log << "Sender: adding new destinator to msg " << str;
		sendto(destfd, str);
	}

}