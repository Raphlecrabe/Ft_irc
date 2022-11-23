#ifndef USER_HPP
# define USER_HPP

# include <iostream>

class User {
	private:
		int _fd;

		std::string _nickname;
		std::string _name;
		std::string _realname;

	public:
		User(int fd);
		~User();

		const int & getFd();

		const std::string & getNickname();
		const std::string & getName();
		const std::string & getRealname();

		void setNickname(std::string & nickname);
		void setName(std::string & name);
		void setRealname(std::string & realname);
};

#endif