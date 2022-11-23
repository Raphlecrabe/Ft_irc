#include "../incs/Listener.hpp"

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

Listener::Listener() : _fd_count(0) {

}

Listener::~Listener() {
	free(this->_pfds);
}

int Listener::init(const char* port, int fd_size) {
	this->_fd_size = fd_size;

	this->_pfds = (struct pollfd *)malloc(sizeof(*_pfds) * this->_fd_size);

	if (this->_pfds == NULL)
		return -1;

	if (launch_listener(port) == -1)
		{
			std::cerr << "Error getting listening socket" << std::endl;
			return 0;
		}

	add_fd(_listenerfd, POLLIN);

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

	return 0;
}

bool Listener::datasComplete(const std::string & datas)
{
	int len = datas.length();

	if (len < 2)
		return false;

	if (datas.substr(len - 2, 2).compare("\r\n"))
		return true;

	return false;
}

std::string Listener::recvdatas(int fd) {
	std::string datas;
	
	char buf[256];

	while (datasComplete(datas) == false) {
		bzero(buf, 256);

		int nbytes = recv(fd, buf, sizeof(buf), 0);
		// check if bytes received until the end!

		if (nbytes <= 0) {
			// Got error or connection closed by client
			if (nbytes == 0) {
				// Connection closed
				std::cout << "pollserver: socket " << fd << " hung up" << std::endl;
			} else {
				std::cerr << "error: recv" << std::endl;
			}

			remove_fd(fd);

			datas.clear();

			break;

		} else
			datas += buf;
	}

	return datas;
}

void	Listener::new_connection() {
	int newfd;
	struct sockaddr_storage remoteaddr;
	socklen_t addrlen;

	char remoteIP[INET6_ADDRSTRLEN];
	
	addrlen = sizeof(remoteaddr);

	newfd = accept(_listenerfd, (struct sockaddr *)&remoteaddr, &addrlen);

	if (newfd == -1) {
		std::cerr << "accept" << std::endl;
	} else {
		add_fd(newfd, POLLIN);

		inet_ntop(remoteaddr.ss_family, get_in_addr((struct sockaddr*)&remoteaddr), remoteIP, INET6_ADDRSTRLEN);

		std::cout << "pollserver: new connection from " << remoteIP << " on socket " << newfd << std::endl;
	}
}

void	Listener::add_fd(int newfd, int events) {
	if (_fd_count == _fd_size) {
		_fd_size *= 2;
		_pfds = (struct pollfd *)realloc(_pfds, sizeof(*_pfds) * _fd_size);
		// PROTECTION!
	}

	fcntl(newfd, F_SETFL, O_NONBLOCK);

	_pfds[_fd_count].fd = newfd;
	_pfds[_fd_count].events = events;

	_fd_count++;
}

void	Listener::remove_fd(int fd) {
	
	int index = -1;

	for (int i = 0; i < _fd_count; i++)
	{
		if (_pfds[i].fd == fd)
		{
			index = i;
			break;
		}
	}
	
	if (index < 0)
		return;

	close(fd);
	
	_pfds[index] = _pfds[_fd_count - 1];

	_fd_count--;
}

int		Listener::pollfds() {
	
	int poll_count = poll(_pfds, _fd_count, -1);

	return poll_count;
}

int		Listener::Hear(int i) {
	if (_pfds[i].revents & POLLIN)
	{	
		if (_pfds[i].fd == _listenerfd)				
			new_connection();
		else
			return _pfds[i].fd;
	}

	return -1;
}

int		Listener::GetFdCount() {
	return this->_fd_count;
}

int		Listener::GetFd(int i) {
	return _pfds[i].fd;
}

void* 	Listener::get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

const char* Listener::MallocErrorException::what() const throw() {
	return "Exception: malloc error";
}