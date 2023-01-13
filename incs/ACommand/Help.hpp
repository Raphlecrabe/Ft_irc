#ifndef HELP_HPP
# define HELP_HPP

# include "ACommand.hpp"

class Help : public ACommand{
	private:

	public:
		Help();
		~Help();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
