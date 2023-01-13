#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <string.h>
#include <unistd.h>

#include <map>

#include "Listener.hpp"

#include "Sender.hpp"

#include "Hub.hpp"

#include "Receiver.hpp"

class Hub;

class Server {
	private:

		Listener	_listener;
		Sender		_sender;
		Hub			_hub;
		Receiver	_receiver;

		std::string _serverName;
		std::string _networkName;
		std::string	_startTime;

		std::string _password;

		void	receive(int fd);
		void	new_user(int fd);
		void	initTime();

		bool datasComplete(const std::string & datas);

	public:
		Server(std::string const &serverName, const char *port, char *password);
		~Server();

		void launch();

		std::string const &getServerName() const;
		std::string const &getServerPassword() const;
		std::string const &getNetworkName() const;
		std::string	const &getStartTime() const;
};

#endif