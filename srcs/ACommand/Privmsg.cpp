#include "../../incs/ACommand/Privmsg.hpp"

Privmsg::Privmsg() : ACommand("PRIVMSG"){

}

Privmsg::~Privmsg() {
	
}

Callback	&Privmsg::cmdExecute(Message & message, Hub & hub) {
	std::string target = message.getParamList()[0];

	User *destinator = hub.get_UserByNickName(target);
	if (destinator)
		msgToUser(destinator, message);

	return this->_callback;
}

void		Privmsg::msgToUser(User *user, Message& message) {
	std::string source = message.getSender()->getNickname();

	std::string params = user->getNickname() + " :" + message.getParamList()[1];

	Message newmessage(source, "PRIVMSG", params);
	newmessage.addDestinator(user);
	this->_callback.addMessage(newmessage);
}

void		Privmsg::msgToChannel(Channel *channel, Message& message) {
	(void)channel;
	std::string format = message.Format();

}