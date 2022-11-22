#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <iostream>
# include "User.hpp"

class Message {
	private:
		User *_sender;

		// the 3 elements that make up an irc message
		std::string _source;
		std::string _command;
		std::string _params;

	public:
		Message(std::string src, std::string cmd, std::string prms);
		Message(char *datas);
		Message(Message const &);
		Message & operator=(Message const &);
		~Message();

		User *destinator;

		std::string Format();
};

#endif