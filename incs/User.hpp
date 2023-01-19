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
		bool _isRegistered;

	public:
		User(int fd);
		~User();

		const int & getFd();

		const std::string & getNickname() const;
		const std::string & getName() const;
		const std::string & getRealname() const;
		const std::vector<Channel *> & getChannels() const;
		int					getNumberOfChannels() const;

		void setAuth(bool);
		bool isAuth();

		void setNickname(std::string const & nickname);
		void setName(std::string const & name);
		void setRealname(std::string const & realname);
		void setNumberOfChannels(int number);
		void AddChannel(Channel *channel);
		void RemoveChannel(Channel *channel);

		void RemoveItselfFromChannels();
		Message getQuitMessage(std::string reason);
		void addAllConnectedUsersToMessage(Message & message);

		bool NicknameIsSet();

		bool IsRegistered();
		void Register();
};

# include "Channel.hpp"

#endif