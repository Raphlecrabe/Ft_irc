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
#include <csignal>

#include "../incs/Define.hpp"
#include "../incs/Server.hpp"
#include "../incs/Listener.hpp"
#include "../incs/Hub.hpp"
#include "../incs/Message.hpp"
#include "../incs/Receiver.hpp"

void requestExit(int sig) {
	(void)sig;
	Server::REQUEST_EXIT = true;
	return;
}

Server::Server(std::string const &serverName, const char *port, char *password) : 	_hub(this),
																					_receiver(_sender, _hub),
																					_serverName(serverName),
																					_password(password) {

	initTime();

	if (_listener.init(port) == -1)
		std::exit(0);

	this->_networkName = "FT_IRC";

	std::signal(SIGINT, requestExit);

	Debug::Log << "Init server with port " << port << std::endl;
}

Server::~Server() {
	std::cout << "Leaving!" << std::endl;
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

bool Server::datasComplete(const std::string & datas)
{
	size_t pos = datas.find("\r\n");

	if (pos == std::string::npos)
		return false;

	return true;
}

void	Server::receive(int fd) {
	
	if (_listener.recvdatas(fd) == false)
	{
		User *user = _hub.getUserByFd(fd);
		if (user)
		{
			Message newmessage = user->getQuitMessage("connection closed by client");
			send(newmessage);
			_hub.RemoveUserByFd(fd);
		}

		_listener.close_connection(fd);

		return;
	}

	std::string const datas = _listener.get_datas_from_fd(fd);

	if (datasComplete(datas) == false)
		return;

	std::cout << "Received: " << datas;

	User * usr = _hub.getUserByFd(fd);

	if (usr == NULL)
		return;

	_receiver.Hear(usr, datas);

	_listener.clear_datas_from_fd(fd);
}

void Server::launch() {

	while (REQUEST_EXIT == false)
	{
		int fd_max = _listener.pollfds();

		if (fd_max == -1)
		{
			perror("poll");
			return;
		}

		for (int i = 0; i < fd_max + 1; i++)
		{
			if (_listener.IsSet(i) == false)
				continue;

			int	recvfd = -1;
			int	ncfd = -1;

			_listener.Hear(i, &recvfd, &ncfd);

			if (ncfd > 0)
				new_user(ncfd);
			else if (recvfd > 0)
				receive(recvfd);

			if (_listener.IsListening(i))
				_sender.Speak(i);

			if (is_programmed_to_close(i) && (_sender.HasSomethingToSayTo(i) == false))
				close_connection(i);
		}
	}
}

bool		Server::is_programmed_to_close(int fd) {
	if (_close_buffer.size() == 0)
		return false;

	std::vector<int>::iterator it;

	for (it = _close_buffer.begin(); it != _close_buffer.end(); it++)
	{
		if (*it == fd)
			return true;
	}

	return false;
}

void		Server::program_to_close(int fd)
{
	if (is_programmed_to_close(fd))
		return;

	_close_buffer.push_back(fd);
}

void		Server::close_connection(int fd) {

	// this->_hub.RemoveUserByFd(fd);

	this->_listener.close_connection(fd);

	std::vector<int>::iterator it;

	for (it = _close_buffer.begin(); it != _close_buffer.end(); it++)
	{
		if (*it == fd)
		{
			_close_buffer.erase(it);
			return;
		}
	}
}

void	Server::send(Message &m)
{
	_sender.sendto(m);
}

std::string const &Server::getServerPassword() const { return this->_password; }
std::string const &Server::getServerName() const { return this->_serverName; }
std::string const &Server::getNetworkName() const { return this->_networkName; }
std::string	const &Server::getStartTime() const { return this->_startTime; }