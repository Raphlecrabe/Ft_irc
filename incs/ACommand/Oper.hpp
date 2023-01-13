#ifndef OPER_HPP
# define OPER_HPP

# include "ACommand.hpp"

class Oper : public ACommand{
	private:

	public:
		Oper();
		~Oper();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
