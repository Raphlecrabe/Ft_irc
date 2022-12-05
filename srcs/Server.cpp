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

#include "../incs/Define.hpp"
#include "../incs/Server.hpp"
#include "../incs/Listener.hpp"
#include "../incs/Hub.hpp"
#include "../incs/Message.hpp"
#include "../incs/Receiver.hpp"

Server::Server(std::string const &serverName, std::string const &networkName) : _hub(this), _receiver(_hub), _serverName(serverName), _networkName(networkName) {

	_listener.init(PORT, 5);

	Debug::Log(std::string("Init server with port ") + std::string(PORT));
}

Server::~Server() {
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
	
	std::cout << "Received: " << datas << std::endl;

	User * usr = _hub.getUserByFd(fd);

	if (usr == NULL)
		return;

	_receiver.Hear(usr, datas);
}

void Server::launch() {

	while (true)
	{
		int poll_count = _listener.pollfds();

		if (poll_count == -1)
		{
			perror("poll");
			return;
		}

		int fd_count = _listener.GetFdCount();

		for (int i = 0; i < fd_count; i++)
		{
			int	recvfd = -1;
			int	ncfd = -1;

			_listener.Hear(i, &recvfd, &ncfd);

			if (ncfd > 0)
				new_user(ncfd);
			else if (recvfd > 0)
				receive(recvfd);
		}
	}
}

	std::string const &Server::getServerName() const { return this->_serverName; }
	std::string const &Server::getNetworkName() const { return this->_networkName; }