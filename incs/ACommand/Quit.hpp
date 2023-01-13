#ifndef QUIT_HPP
# define QUIT_HPP

# include "ACommand.hpp"

class Quit : public ACommand{
	private:

	public:
		Quit();
		~Quit();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
