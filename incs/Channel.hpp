#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <vector>
# include <string>
# include "../incs/Define.hpp"
# include "../incs/User.hpp"

class Channel {
	private:
		std::string			_name;
		std::string			_topic;
		std::vector<User &>	_users;
		std::vector<int>	_users_fd;
		int					_client_limit;

	public:
		Channel();
		~Channel();

		std::string	get_name();
		std::string	get_topic();
		std::vector<User &>	get_users();
		std::vector<int>	get_users_fd();
		Channel & operator=(Channel const &);
		void	AddFd(int fd);
		int	AddUser(User &);
		int	RemoveUser(User &);
};

#endif