#include "../incs/Listener.hpp"
#include "../incs/Debug.hpp"

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
#include <cstdlib>
#include <stdio.h>
#include <sstream>

Listener::Listener() {

}

Listener::~Listener() {
	
}

int Listener::init(const char* port) {
	FD_ZERO(&(this->_master));

	if (launch_listener(port) == -1)
	{
		std::cerr << "Error getting listening socket" << std::endl;
		return 0;
	}

	return 0;
}

int		Listener::launch_listener(const char* port) {
	int yes=1;
	int rv;

	struct addrinfo hints, *ai, *list;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	
	if ((rv = getaddrinfo(NULL, port, &hints, &ai)) != 0) {
		std::cerr << "selectserver: " << gai_strerror(rv);
		return -1;
	}

	for (list = ai; list != NULL; list = list->ai_next) {
		this->_listenerfd = socket(list->ai_family, list->ai_socktype, list->ai_protocol);

		if (_listenerfd < 0)
			continue;

		setsockopt(_listenerfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

		if (bind(_listenerfd, list->ai_addr, list->ai_addrlen) < 0) {
			close(_listenerfd);
			continue;
		}

		break;
	}

	if (list == NULL)
		return -1;

	freeaddrinfo(ai);

	if (listen(_listenerfd, 10) == -1) {
		return -1;
	}

	FD_SET(_listenerfd, &_master);

	_fd_max = _listenerfd;

	return 0;
}

bool Listener::datasComplete(const std::string & datas)
{
	int len = datas.length();

	if (len < 2)
		return false;

	return (datas.substr(len - 2, 2).compare("\r\n") == 0);
}

std::string Listener::recvdatas(int fd) {
	std::string datas;
	
	char buf[256];

	while (datasComplete(datas) == false) {	
		bzero(buf, 256);

		int nbytes = recv(fd, buf, sizeof(buf) - 1, 0);

		if (nbytes <= 0) {
			// Got error or connection closed by client
			if (nbytes == 0) {
				// Connection closed
				std::cout << "pollserver: socket " << fd << " hung up" << std::endl;
			} else {
				std::cerr << "error: recv" << std::endl;
			}
			
			close(fd);
			FD_CLR(fd, &_master);

			datas.clear();

			break;

		} else {
			datas += buf;
		}
	}

	Debug::Log(std::string("Listener: received: " + datas));

	return datas;
}

int	Listener::new_connection() {
	int newfd;
	struct sockaddr_storage remoteaddr;
	socklen_t addrlen;

	char remoteIP[INET6_ADDRSTRLEN];
	
	addrlen = sizeof(remoteaddr);

	newfd = accept(_listenerfd, (struct sockaddr *)&remoteaddr, &addrlen);

	if (newfd == -1) {
		std::cerr << "accept" << std::endl;
		return -1;
	} else {
		FD_SET(newfd, &_master);

		fcntl(newfd, F_SETFL, O_NONBLOCK);

		if (newfd > _fd_max)
			_fd_max = newfd;

		inet_ntop(remoteaddr.ss_family, get_in_addr((struct sockaddr*)&remoteaddr), remoteIP, INET6_ADDRSTRLEN);

		std::cout << "pollserver: new connection from " << remoteIP << " on socket " << newfd << std::endl;

		return newfd;
	}
}

int		Listener::pollfds() {
	_readfds = _master;
	_writefds = _master;

	FD_CLR(_listenerfd, &_writefds);

	select(_fd_max + 1, &_readfds, &_writefds, NULL, NULL);

	return _fd_max;
}

void	Listener::Hear(int i, int *recvfd, int *ncfd) {

	if (FD_ISSET(i, &_readfds))
	{
		if (i == _listenerfd)
			*ncfd = new_connection();
		else
			*recvfd = i;
	}
}

void* 	Listener::get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}