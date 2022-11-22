#ifndef SERVER_HPP
# define SERVER_HPP

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

#include <map>

#include "Sender.hpp"

#include "User.hpp"
#include "Channel.hpp"

#include "Replier.hpp"
#include "AReply.hpp"
#include "Rpl_Welcome.hpp"

class Server {
	private:
		int				_fd_count;
		int				_fd_size;
		struct pollfd 	*_pfds;

		int				_listener;

		Channel main_channel;
		Sender	sender;
		Replier *replier;

		std::vector<User *> _users;

		void	*get_in_addr(struct sockaddr *sa);

		int 	launch_listener();

		void	add_fd(int fd, int events);
		void	remove_fd(int fd);

		void	new_connection();
		void	receive(int fd);

		void	greeting(User &);

	public:
		Server(int fd_size);
		~Server();

		void init();
		void launch();

		class MallocErrorException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif