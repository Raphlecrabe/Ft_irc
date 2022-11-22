#include "../incs/Sender.hpp"
#include "../incs/Message.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <errno.h>

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
}

void Sender::sendto(int fd, std::string msg) {

	sendto(fd, msg.c_str(), msg.size() + 1);
}

void Sender::sendto(Message & msg) {

	if (msg.destinator == NULL)
	{
		throw Sender::SendErrorException();
		return;
	}

	int	destfd = msg.destinator->getFd();
	std::string str = msg.Format();

	sendto(destfd, str);
}

const char* Sender::SendErrorException::what() const throw() {
	return "Sender exception: <send> returned an error, errno = " + errno;
}

const char* Sender::NoDestinationException::what() const throw() {
	return "Sender exception: no destinator specified";
}