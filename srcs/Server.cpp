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

void	Server::greeting(User & usr) {
	std::string src = "lebestserver.com";
	std::string cmd = "001";
	std::string params = "fbelthoi :Welcome to the Internet Relay Network fbelthoi!fbelthoi@localhost";

	Message msg(src, cmd, params);
	msg.destinator = &usr;

	try {
		_sender.sendto(msg);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Server::receive(int fd) {
	
	std::string datas = _listener.recvdatas(fd);

	if (datas.empty())
	{
		//_hub.RemoveUserByFd(fd);
		return;
	}
	
	std::cout << "Received: " << datas << std::endl;
	
	User new_user = _hub.CreateUser(fd);

	_receiver.Hear(new_user, datas);
	//Server::greeting(new_user);
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
			int fd = _listener.Hear(i);

			if (fd > 0)
				receive(fd);
		}
	}
}