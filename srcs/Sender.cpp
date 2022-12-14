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

void Sender::Speak(int fd) {
	if (_buffers.count(fd) == 0 || _buffers[fd].size() == 0)
		return;

	std::vector<std::string>::iterator it;

	for (it = _buffers[fd].begin(); it != _buffers[fd].end(); it++)
	{
		_send(fd, *it);
	}

	_buffers[fd].clear();
}

void Sender::_send(int fd, std::string msg) {
	int 			res;
	unsigned int	sent = 0;

	unsigned int	size = msg.size();
	const char* 	datas = msg.c_str();

	while (sent != size)
	{
		const char *r_datas = &datas[sent];
		int	r_size = size - sent;

		res = send(fd, r_datas, r_size, 0);

		if (res == -1)
		{
			throw Sender::SendErrorException();
			return;
		}

		sent += res;
	}

	std::string log = "Sender: sent " + std::string(datas);
	Debug::Log(log);
}

void Sender::sendto(int fd, const char *datas, int size) {
	//Exists only for compatibility
	(void)size;
	sendto(fd, std::string(datas));

	return;
}

void Sender::sendto(int fd, std::string msg) {
	if (_buffers.count(fd) == 0) {
		std::vector<std::string> datas;
		std::pair<int, std::vector<std::string> > newpair(fd, datas);
		_buffers.insert(newpair);
	}

	_buffers[fd].push_back(msg);
}

void Sender::sendto(Message const & msg) {
	std::vector<User *> const destinators = msg.getDestinators();
	
	if (destinators.size() == 0)
	{
		throw Sender::NoDestinatorException();
		return;
	}

	std::vector<User *>::const_iterator it;

	for (it = destinators.begin(); it != destinators.end(); it++)
	{
		int	destfd = (*it)->getFd();
		std::string str = msg.Format();
		sendto(destfd, str);
	}

}

const char* Sender::SendErrorException::what() const throw() {
	return "Sender exception: <send> returned an error";
}

const char* Sender::NoDestinatorException::what() const throw() {
	return "Sender exception: no destinator specified";
}