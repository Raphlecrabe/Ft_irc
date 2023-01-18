#ifndef KILL_HPP
# define KILL_HPP

# include "ACommand.hpp"

class Kill : public ACommand{
	private:

	public:
		Kill();
		~Kill();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
