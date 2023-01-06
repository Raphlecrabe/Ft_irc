#ifndef INVITE_HPP
# define INVITE_HPP

# include "ACommand.hpp"

class Invite : public ACommand{
	private:

	public:
		Invite();
		~Invite();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
