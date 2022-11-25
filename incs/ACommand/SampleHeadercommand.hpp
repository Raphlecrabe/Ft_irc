#ifndef NAME_HPP
# define NAME_HPP

# include "ACommand.hpp"

class Name : public ACommand{
	private:

	public:
		Name();
		~Name();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif