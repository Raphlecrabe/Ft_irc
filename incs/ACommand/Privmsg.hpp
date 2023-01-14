#ifndef PRIVMSG_HPP
# define PRIVMSG_HPP

# include "ACommand.hpp"

class Privmsg : public ACommand{
	private:

	public:
		Privmsg();
		~Privmsg();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif