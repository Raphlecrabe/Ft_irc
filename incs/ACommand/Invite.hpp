#ifndef INVITE_HPP
# define INVITE_HPP

# include "ACommand.hpp"

class Invite : public ACommand{
	private:

	public:
		Invite();
		~Invite();

		Callback	&cmdExecute(Message &message, Hub &hub);
		int	userTest(Message message, std::string chanparam, std::string nickparam, Channel *channel);
};

#endif
