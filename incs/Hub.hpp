#ifndef HUB_HPP
# define HUB_HPP

# include <iostream>
# include <map>
# include <vector>

class Hub;
class Channel;
class Message;

# include "Channel.hpp"
# include "User.hpp"
# include <string>
# include <stdexcept>

class Server;
class User;

class Hub {
	private:
		Server *_server;

		std::vector<User *> 				_users;
		std::vector<Channel *>				_channels;
		std::vector<User *> 				_ircOperators;
		std::map<std::string, std::string>	_operatorConfig;
		int						_numberofchannels;
		
		std::string				*_messageOfTheDay;

		std::vector<User *>::iterator findUserByFd(int fd);

		bool chanNameIsValid(std::string const &);

	public:
		Hub(Server *);
		~Hub();

		User & CreateUser(int fd);
		void RemoveUserByFd(int fd);
		User * getUserByFd(int fd);
		std::vector<User *> const & getUserList() const;
		User *get_UserByNickName(std::string nickname);

		std::string const &getServerName() const;
		std::string const &getNetworkName() const;
		std::string	const &getStartTime() const;
		std::string const &getServerPassword() const;

		void				setMessageOfTheDay(std::string);
		std::string const	*getMessageOfTheDay() const;

		Channel	&CreateChannel(std::string &name, User *user);
		Channel *getChannelByName(std::string const &name) const;
		void	removeChannelByName(std::string const & name); // TO DO : faut encore le coder
		std::vector<Channel *> const &getChannelList() const;

		int	getNumberOfChannels() const;

		int		isIrcOperator(User *user);
		void	addIrcOperator(User *user);

		int	isInConfig(std::string name, std::string password);

		void 		program_to_close(int fd);

		void	addQuitUsersInMessage(User *user, Message &message);

		//EXCEPTIONS FOR CREATING A CHANNEL
		class TooManyChannels : public std::exception
		{
			public:

			virtual const	char	*what() const throw()
			{
				return ("ERR_TOOMANYCHANNELS");
			}
		};
		class ChannelMaxReached : public std::exception
		{
			public:

			virtual const	char	*what() const throw()
			{
				return ("ERR_MAXCHANNELS");
			}
		};
		class BadChannelName : public std::exception
		{
			public:

			virtual const	char	*what() const throw()
			{
				return ("ERR_BADCHANMASK");
			}
		};
		class ChannelIsFull : public std::exception
		{
			public:

			virtual const	char	*what() const throw()
			{
				return ("ERR_CHANNELISFULL");
			}
		};
};

#endif
