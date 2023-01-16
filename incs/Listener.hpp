#ifndef LISTENER_HPP
# define LISTENER_HPP

# include <iostream>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/select.h>
# include <map>

class Listener {
	private:
		int				_fd_max;
		fd_set			_master;
		fd_set			_readfds;
		fd_set			_writefds;

		int				_listenerfd;

		std::map<int, std::string> _buffers;

		void	*get_in_addr(struct sockaddr *sa);

		int 	launch_listener(const char* port);

		bool	datasComplete(const std::string &);

	public:
		Listener();
		~Listener();

		int init(const char* port);
		int pollfds();

		bool 		recvdatas(int fd);
		int			new_connection();

		void	Hear(int i, int *recvfd, int *ncfd);
		bool	IsListening(int fd);

		std::string const & get_datas_from_fd(int fd);
		void				clear_datas_from_fd(int fd);

		void	close_connection(int fd);

		bool 	IsSet(int fd);
};

#endif