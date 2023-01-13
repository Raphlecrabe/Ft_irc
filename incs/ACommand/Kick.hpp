#ifndef KICK_HPP
# define KICK_HPP

# include "ACommand.hpp"

class Kick : public ACommand{
	private:

	public:
		Kick();
		~Kick();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
