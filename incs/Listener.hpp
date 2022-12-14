#ifndef LISTENER_HPP
# define LISTENER_HPP

# include <iostream>

class Listener {
	private:
		int				_fd_max;
		fd_set			_master;
		fd_set			_readfds;
		fd_set			_writefds;

		int				_listenerfd;

		void	*get_in_addr(struct sockaddr *sa);

		int 	launch_listener(const char* port);

		bool	datasComplete(const std::string &);

	public:
		Listener();
		~Listener();

		int init(const char* port);
		int pollfds();

		std::string recvdatas(int fd);
		int			new_connection();

		void	Hear(int i, int *recvfd, int *ncfd);
};

#endif