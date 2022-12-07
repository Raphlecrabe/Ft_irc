#ifndef USER_HPP
# define USER_HPP

# include <iostream>
# include "Define.hpp"
# include <vector>

class Channel;

class User {
	private:
		int _fd;

		std::string _nickname;
		std::string _name;
		std::string _realname;
		std::vector<Channel *> _channels;

		int	_number_of_channels;

	public:
		User(int fd);
		~User();

		const int & getFd();

		const std::string & getNickname() const;
		const std::string & getName() const;
		const std::string & getRealname() const;
		const std::vector<Channel *> & getChannels() const;
		int					getNumberOfChannels() const;

		void setNickname(std::string & nickname);
		void setName(std::string & name);
		void setRealname(std::string & realname);
		void setNumberOfChannels(int number);
		void AddChannel(Channel *channel);
};

# include "Channel.hpp"

#endif