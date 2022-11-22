#ifndef LISTENER_HPP
# define LISTENER_HPP

# include <iostream>

class Listener {
	private:
		int				_fd_count;
		int				_fd_size;
		struct pollfd	*_pfds;

		int				_listenerfd;

		void	*get_in_addr(struct sockaddr *sa);

		int 	launch_listener(const char* port);

		void	add_fd(int fd, int events);
		void	remove_fd(int fd);

		void	new_connection();

	public:
		Listener();
		~Listener();

		int init(const char* port, int fd_size);
		int pollfds();

		std::string receive(int fd);

		int	GetFdCount();
		int	GetFd(int i);
		int	Process(int i); // Gives fd to receive if there are datas

		class MallocErrorException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif