#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <string.h>
#include <unistd.h>

#include <map>

#include "Listener.hpp"

#include "Sender.hpp"

#include "User.hpp"

#include "Hub.hpp"

#include "Replier.hpp"
#include "AReply.hpp"
#include "Rpl_Welcome.hpp"

class Server {
	private:

		Listener	_listener;
		Sender		sender;
		Replier 	*replier;
		Hub			_hub;

		void	receive(int fd);

		void	greeting(User &);

	public:
		Server(int fd_size);
		~Server();

		void launch();
};

#endif