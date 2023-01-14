#ifndef PRIVMSG_HPP
# define PRIVMSG_HPP

# include "ACommand.hpp"

class Privmsg : public ACommand{
	private:
		void	msgToUser(User *user, Message& message);
		void	msgToChannel(Channel *channel, Message& message);

	public:
		Privmsg();
		~Privmsg();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif