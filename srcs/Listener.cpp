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

bool Listener::recvdatas(int fd) {	
	char buf[256];

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
		
		//close_connection(fd);

		return false;

	}
	
	_buffers[fd] += buf;

	Debug::Log << "Listener: received: " << buf;

	return true;
}

std::string const & Listener::get_datas_from_fd(int fd) {
	return this->_buffers[fd];
}

void	Listener::clear_datas_from_fd(int fd) {
	
	std::string datas = _buffers[fd];

	size_t pos = datas.find("\r\n");

	while (pos != std::string::npos)
	{
		datas = datas.substr(pos + 2);
		pos = datas.find("\r\n");
	}

	this->_buffers[fd] = datas;
}

int	Listener::new_connection() {
	Debug::Log << "Listener: new_connection" << std::endl;

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

		std::pair<int, std::string> pair = std::make_pair<int, std::string>(newfd, "");
		_buffers.insert(pair);

		if (newfd > _fd_max)
			_fd_max = newfd;

		inet_ntop(remoteaddr.ss_family, get_in_addr((struct sockaddr*)&remoteaddr), remoteIP, INET6_ADDRSTRLEN);

		std::cout << "pollserver: new connection from " << remoteIP << " on socket " << newfd << std::endl;

		return newfd;
	}
}

void	Listener::close_connection(int fd) {
	close(fd);
	FD_CLR(fd, &_master);

	std::map<int, std::string>::iterator it = _buffers.find(fd);
	if (it != _buffers.end())
		_buffers.erase(fd);
}

bool 	Listener::IsSet(int fd) {
	if (fd == _listenerfd)
		return true;

	std::map<int, std::string>::iterator it = _buffers.find(fd);

	if (it == _buffers.end())
		return false;

	return true;
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

bool	Listener::IsListening(int fd) {
	return (FD_ISSET(fd, &_writefds));
}

void* 	Listener::get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}