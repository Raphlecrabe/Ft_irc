#ifndef NOTICE_HPP
# define NOTICE_HPP

# include "ACommand.hpp"

class Notice : public ACommand{
	private:

		void		msgToUser(User *user, Message& message);
		void		msgToChannel(Channel *channel, Message& message);
	public:
		Notice();
		~Notice();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif