#ifndef NAMES_HPP
# define NAMES_HPP

# include "ACommand.hpp"

class Names : public ACommand{
	private:

	public:
		Names();
		~Names();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
