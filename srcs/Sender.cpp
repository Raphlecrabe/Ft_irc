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

void Sender::sendto(int fd, const char *datas, int size) {

	int res;
	int	sent = 0;

	while (sent != size)
	{
		res = send(fd, datas, size, 0);

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

void Sender::sendto(int fd, std::string msg) {

	sendto(fd, msg.c_str(), msg.size() + 1);
}

void Sender::sendto(Message const & msg) {

	std::vector<User *> const destinators = msg.getDestinators();
	
	if (destinators.size() == 0)
	{
		throw Sender::SendErrorException();
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
	std::stringstream ss;
	ss << errno;

	std::string str = "Sender exception: <send> returned an error: " + ss.str();

	const char* c = str.c_str();

	return c;
}

const char* Sender::NoDestinationException::what() const throw() {
	return "Sender exception: no destinator specified";
}