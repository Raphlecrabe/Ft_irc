#ifndef PING_HPP
# define PING_HPP

# include "ACommand.hpp"

class Ping : public ACommand{
	private:

	public:
		Ping();
		~Ping();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif