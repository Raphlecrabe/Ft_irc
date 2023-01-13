#ifndef INFO_HPP
# define INFO_HPP

# include "ACommand.hpp"

class Info : public ACommand{
	private:

	public:
		Info();
		~Info();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
