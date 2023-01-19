#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <iostream>
# include <vector>
# include "User.hpp"

class Message {
	private:
		User * _sender;
		std::vector<User *> _destinators;

		// the 3 elements that make up an irc message
		std::string _source;
		std::string _command;
		std::string _params;
		std::vector<std::string> _paramlist;

		void parse(std::string raw);
		void parseparams();

	public:
		Message();
		Message(std::string src, std::string cmd, std::string prms);
		Message(User * sender, std::string datas);
		Message(Message const &);
		Message & operator=(Message const &);
		~Message();

		void addDestinator(User *dest);
		std::vector<User *> const &getDestinators() const;

		std::string const & getSource() const;
		std::string const & getCommand() const;
		std::string const & getParams() const;
		std::vector<std::string> const & getParamList() const;

		User * getSender();

		std::string Format() const;
};

#endif