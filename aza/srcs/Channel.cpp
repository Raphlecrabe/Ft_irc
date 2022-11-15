#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <poll.h>
#include <unistd.h>
#include <fcntl.h>

#include "../incs/Channel.hpp"

Channel::Channel() {

}

Channel::~Channel() {

}

void Channel::add_fd(int fd)
{
	_fds.push_back(fd);
}

void Channel::send_all(int sender_fd, char * message, int nbytes)
{
	std::vector<int>::iterator it;

	for (it = _fds.begin(); it != _fds.end(); it++) {

		int dest_fd = *it;

		if (dest_fd != sender_fd) {
			if (send(dest_fd, message, nbytes, 0) == -1)
				std::cerr << "error: send" << std::endl;
		}
	}
}