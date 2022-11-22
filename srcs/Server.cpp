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

#include "../incs/Message.hpp"
#include "../incs/Sender.hpp"

#include "../incs/Replier.hpp"
#include "../incs/AReply.hpp"
#include "../incs/Rpl_Welcome.hpp"

Server::Server(int fd_size) {
	
	_listener.init(PORT, fd_size);

	std::vector<AReply *> replies;
	replies.push_back(new Rpl_Welcome());

	this->replier = new Replier(replies);
}

Server::~Server() {
	delete replier;
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
	std::string datas;
	
	try {
		datas = _listener.receive(fd);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return;
	}

	if (datas == "")
		return;
	
	std::cout << "Received: " << datas << std::endl;
	User *new_usr = new User(fd);
	_users.push_back(new_usr);
	Server::greeting(*new_usr);
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
			int fd = _listener.Process(i);

			if (fd > 0)
				receive(fd);
		}
	}
}