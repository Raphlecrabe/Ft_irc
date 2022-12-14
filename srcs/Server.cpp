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
#include <sstream>

#include "../incs/Define.hpp"
#include "../incs/Server.hpp"
#include "../incs/Listener.hpp"
#include "../incs/Hub.hpp"
#include "../incs/Message.hpp"
#include "../incs/Receiver.hpp"

Server::Server(std::string const &serverName, const char *port, char *password) : 	_hub(this),
																					_receiver(_sender, _hub),
																					_serverName(serverName),
																					_password(password) {
	
	initTime();

	_listener.init(port);

	this->_networkName = "FT_IRC";

	Debug::Log(std::string("Init server with port ") + std::string(port));
}

Server::~Server() {
}

void	Server::initTime() {
	time_t now_c = time(NULL);
    struct tm *parts = localtime(&now_c);

	std::stringstream stream;

	stream << parts->tm_mday << "/" << 1 + parts->tm_mon << "/" << 1900 + parts->tm_year;

	stream >> this->_startTime;
}

void	Server::new_user(int fd) {
	_hub.CreateUser(fd);
}

void	Server::receive(int fd) {
	
	std::string datas = _listener.recvdatas(fd);

	if (datas.empty())
	{
		_hub.RemoveUserByFd(fd);
		return;
	}
	
	std::cout << "Received: " << datas;

	User * usr = _hub.getUserByFd(fd);

	if (usr == NULL)
		return;

	_receiver.Hear(usr, datas);
}

void Server::launch() {

	while (true)
	{
		int fd_max = _listener.pollfds();

		if (fd_max == -1)
		{
			perror("poll");
			return;
		}

		for (int i = 0; i < fd_max + 1; i++)
		{
			int	recvfd = -1;
			int	ncfd = -1;

			_listener.Hear(i, &recvfd, &ncfd);

			if (ncfd > 0)
				new_user(ncfd);
			else if (recvfd > 0)
				receive(recvfd);

			if (_listener.IsListening(i))
				_sender.Speak(i);
		}
	}
}

std::string const &Server::getServerName() const { return this->_serverName; }
std::string const &Server::getNetworkName() const { return this->_networkName; }
std::string	const &Server::getStartTime() const { return this->_startTime; }