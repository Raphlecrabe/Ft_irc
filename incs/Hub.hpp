#ifndef HUB_HPP
# define HUB_HPP

# include <iostream>
# include <map>
# include <vector>

# include "User.hpp"

class Hub {
	private:
		std::vector<User *> _users;

	public:
		Hub();
		~Hub();

		User & CreateUser(int fd);
		void RemoveUserByFd(int fd);

		std::vector<User *> const & getUserList() const;
};

#endif
