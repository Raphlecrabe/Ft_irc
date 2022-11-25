#ifndef CAP_HPP
# define CAP_HPP

# include "ACommand.hpp"

class Cap : public ACommand{
	private:

	public:
		Cap();
		~Cap();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif