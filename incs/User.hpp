#ifndef USER_HPP
# define USER_HPP

# include <iostream>
# include "Define.hpp"
# include <vector>

class Channel;
class Message;

class User {
	private:
		int _fd;

		std::string _nickname;
		std::string _name;
		std::string _realname;
		std::vector<Channel *> _channels;

		int	_number_of_channels;

		bool _isAuth; //is the user authenticated ? (= has sent the right password)

	public:
		User(int fd);
		~User();

		const int & getFd();

		const std::string & getNickname() const;
		const std::string & getName() const;
		const std::string & getRealname() const;
		const std::vector<Channel *> & getChannels() const;
		int					getNumberOfChannels() const;

		void setAuth();
		bool isAuth();

		void setNickname(std::string & nickname);
		void setName(std::string & name);
		void setRealname(std::string & realname);
		void setNumberOfChannels(int number);
		void AddChannel(Channel *channel);

		void RemoveItselfFromChannels();
		Message getQuitMessage(std::string reason);

		bool NicknameIsSet();
};

# include "Channel.hpp"

#endif