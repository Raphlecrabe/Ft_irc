#ifndef HUB_HPP
# define HUB_HPP

# include <iostream>
# include <map>

# include "User.hpp"

class Hub {
	private:
		std::map<int, User *> _users;

	public:
		Hub();
		~Hub();

		User & CreateUser(int fd);
		void RemoveUserByFd(int fd);
};

#endif
