#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <vector>
# include <string>
# include <map>
# include "../incs/Define.hpp"
# include "../incs/User.hpp"
# include "Message.hpp"

class	Message;

class Channel {
	private:
		std::string			_name;
		std::string			_topic;
		std::vector<User *>	_users;
		std::vector<int>	_users_fd;
		int					_client_limit;
		std::map<char, std::string> _modes;

	public:
		Channel(std::string &name);
		~Channel();

		std::string	const &get_name() const;
		std::string	const &get_topic() const;
		std::vector<User *>	const &get_users() const;
		std::vector<int>	const &get_users_fd() const;
		void	AddFd(int fd);
		int		AddUser(User *);
		int		RemoveUser(User &);

		void	ChangeTopic(std::string name);

		void	addDestinatorsExceptOneInMessage(User *user, Message &message);

		int	UserIsInChannel(User *user);

		void 	SetClientLimit(int);
		void	RemoveClientLimit();

		std::string const getModestring();
		std::string const getModearguments();
};

#endif