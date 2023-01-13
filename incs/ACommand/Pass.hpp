#ifndef PASS_HPP
# define PASS_HPP

# include "ACommand.hpp"

class Pass : public ACommand{
	private:

	public:
		Pass();
		~Pass();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
