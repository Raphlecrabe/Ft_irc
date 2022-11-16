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

#include "Channel.hpp"
#include "Sender.hpp"
#include "Format.hpp"

#include "../incs/Replier.hpp"
#include "../incs/AReply.hpp"
#include "../incs/Rpl_Welcome.hpp"

class Server {
	private:
		int				_fd_count;
		int				_fd_size;
		struct pollfd 	*_pfds;

		int				_listener;

		Channel	main_channel;
		Sender	sender;
		Format	format;
		Replier *replier;

		void	*get_in_addr(struct sockaddr *sa);

		int 	launch_listener();

		void	add_fd(int fd, int events);
		void	remove_fd(int fd);

		void	new_connection();
		void	receive(int fd);

		void	greeting(int fd);

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