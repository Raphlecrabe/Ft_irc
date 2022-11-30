#ifndef JOIN_HPP
# define JOIN_HPP

# include "ACommand.hpp"

class Join : public ACommand{
	private:

	public:
		Join();
		~Join();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif