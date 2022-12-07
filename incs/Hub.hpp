#ifndef HUB_HPP
# define HUB_HPP

# include <iostream>
# include <map>
# include <vector>
# include "Channel.hpp"
# include "User.hpp"
# include <string>
# include <stdexcept>

class Server;

class Hub {
	private:
		Server *_server;

		std::vector<User *> _users;
		std::vector<Channel *>	_channels;
		int						_numberofchannels;

		std::vector<User *>::iterator findUserByFd(int fd);

	public:
		Hub(Server *);
		~Hub();

		User & CreateUser(int fd);
		void RemoveUserByFd(int fd);
		User * getUserByFd(int fd);
		std::vector<User *> const & getUserList() const;

		std::string const &getServerName() const;
		std::string const &getNetworkName() const;
		std::string	const &getStartTime() const;

		Channel	&CreateChannel(std::string &name, User &user);
		Channel *getChannelByName(std::string &name) const;
		void	removeChannelByName(std::string &name); // TO DO : faut encore le coder
		std::vector<Channel *> const &getChannelList() const;

		int	getNumberOfChannels() const;

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
				return ("ERR_BADCHANNELMASK");
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
