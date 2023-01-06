#ifndef LIST_HPP
# define LIST_HPP

# include "ACommand.hpp"

class List : public ACommand{
	private:

	public:
		List();
		~List();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
