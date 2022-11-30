#ifndef HUB_HPP
# define HUB_HPP

# include <iostream>
# include <map>
# include <vector>

# include "User.hpp"

class Server;

class Hub {
	private:
		Server *_server;

		std::vector<User *> _users;

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
};

#endif
