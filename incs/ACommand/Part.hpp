#ifndef PART_HPP
# define PART_HPP

# include "ACommand.hpp"

class Part : public ACommand{
	private:

	public:
		Part();
		~Part();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
