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
#include <stdio.h>
#include <cstdlib>

#define PORT "9034"

#include "../incs/Server.hpp"

#include "../incs/User.hpp"

#include "../incs/Message.hpp"
#include "../incs/Sender.hpp"

#include "../incs/Replier.hpp"
#include "../incs/AReply.hpp"
#include "../incs/Rpl_Welcome.hpp"

Server::Server(int fd_size) : _fd_count(0), _fd_size(fd_size) {
	this->_pfds = (struct pollfd *)malloc(sizeof(*_pfds) * _fd_size);

	if (this->_pfds == NULL) {
		throw Server::MallocErrorException();
	}

	std::vector<AReply *> replies;
	replies.push_back(new Rpl_Welcome());

	this->replier = new Replier(replies);

	Server::init();
}

Server::~Server() {
	free(_pfds);
	delete replier;
}

void* 	Server::get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int		Server::launch_listener() {
	int yes=1;
	int rv;

	struct addrinfo hints, *ai, *list;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	
	if ((rv = getaddrinfo(NULL, PORT, &hints, &ai)) != 0) {
		std::cerr << "selectserver: " << gai_strerror(rv);
		return -1;
	}

	for (list = ai; list != NULL; list = list->ai_next) {
		this->_listener = socket(list->ai_family, list->ai_socktype, list->ai_protocol);

		if (_listener < 0)
			continue;

		setsockopt(_listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

		if (bind(_listener, list->ai_addr, list->ai_addrlen) < 0) {
			close(_listener);
			continue;
		}

		break;
	}

	if (list == NULL)
		return -1;

	freeaddrinfo(ai);

	if (listen(_listener, 10) == -1) {
		return -1;
	}

	return 0;
}

void	Server::add_fd(int newfd, int events) {
	if (_fd_count == _fd_size) {
		_fd_size *= 2;
		_pfds = (struct pollfd *)realloc(_pfds, sizeof(*_pfds) * _fd_size);
	}

	fcntl(newfd, F_SETFL, O_NONBLOCK);

	_pfds[_fd_count].fd = newfd;
	_pfds[_fd_count].events = events;

	_fd_count++;
}

void	Server::remove_fd(int fd) {
	
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

void	Server::new_connection() {
	int newfd;
	struct sockaddr_storage remoteaddr;
	socklen_t addrlen;

	char remoteIP[INET6_ADDRSTRLEN];
	
	addrlen = sizeof(remoteaddr);

	newfd = accept(_listener, (struct sockaddr *)&remoteaddr, &addrlen);

	if (newfd == -1) {
		std::cerr << "accept" << std::endl;
	} else {
		add_fd(newfd, POLLIN);

		inet_ntop(remoteaddr.ss_family, get_in_addr((struct sockaddr*)&remoteaddr), remoteIP, INET6_ADDRSTRLEN);

		std::cout << "pollserver: new connection from " << remoteIP << " on socket " << newfd << std::endl;
	}
}

void	Server::greeting(User & usr) {
	std::string src = "lebestserver.com";
	std::string cmd = "001";
	std::string params = replier->getReplyByName("RPL_WELCOME");

	Message msg(src, cmd, params);
	msg.destinator = &usr;

	try {
		sender.sendto(msg);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Server::receive(int fd) {
	char buf[256];

	int nbytes = recv(fd, buf, sizeof(buf), 0);

	int sender_fd = fd;

	if (nbytes <= 0) {
		// Got error or connection closed by client
		if (nbytes == 0) {
			// Connection closed
			std::cout << "pollserver: socket " << sender_fd << " hung up" << std::endl;
		} else {
			std::cerr << "error: recv" << std::endl;
		}

		remove_fd(fd);

	} else {
		std::cout << "Received: " << buf << std::endl;
		User *new_usr = new User(sender_fd);
		_users.push_back(new_usr);
		Server::greeting(*new_usr);
	}
}

void Server::init() {

	if (launch_listener() == -1)
	{
		std::cerr << "Error getting listening socket" << std::endl;
		return;
	}

	add_fd(_listener, POLLIN);
}

void Server::launch() {

	while (true)
	{
		int poll_count = poll(_pfds, _fd_count, -1);

		if (poll_count == -1)
		{
			perror("poll");
			return;
		}

		for (int i = 0; i < _fd_count; i++)
		{
			if (_pfds[i].revents & POLLIN)
			{	
				if (_pfds[i].fd == _listener)				
					new_connection();
				else
					receive(_pfds[i].fd);
			}
		}
	}
}

const char* Server::MallocErrorException::what() const throw() {
	return "Exception: malloc error";
}