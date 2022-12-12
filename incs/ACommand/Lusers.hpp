#ifndef LUSERS_HPP
# define LUSERS_HPP

# include "ACommand.hpp"

class Lusers : public ACommand{
	private:

	public:
		Lusers();
		~Lusers();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
