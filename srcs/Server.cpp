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

#include "../incs/Listener.hpp"

#include "../incs/User.hpp"

#include "../incs/Hub.hpp"

#include "../incs/Message.hpp"
#include "../incs/Sender.hpp"

#include "../incs/Receiver.hpp"

#include "../incs/Replyer.hpp"
#include "../incs/AReply/AReply.hpp"
#include "../incs/AReply/Rpl_Welcome.hpp"

Server::Server(int fd_size) : _receiver(_hub) {
	
	_listener.init(PORT, fd_size);
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

	_receiver.Hear(*usr, datas);
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