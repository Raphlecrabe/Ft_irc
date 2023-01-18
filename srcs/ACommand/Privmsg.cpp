#include "../../incs/ACommand/Privmsg.hpp"

Privmsg::Privmsg() : ACommand("PRIVMSG"){

}

Privmsg::~Privmsg() {
	
}

Callback	&Privmsg::cmdExecute(Message & message, Hub & hub) {
	if (message.getParamList().size() == 0)
		return this->_callback;
	
	std::string target = message.getParamList()[0];
	
	if (target[0] == '#')
	{
		Channel *channel = hub.getChannelByName(target);
		if (channel)
			msgToChannel(channel, message);
	} else {
		User *destinator = hub.get_UserByNickName(target);
		if (destinator)
			msgToUser(destinator, message);
		else
			this->_callback.addReply("ERR_NOSUCHNICK", target);
	}

	return this->_callback;
}

void		Privmsg::msgToUser(User *user, Message& message) {
	Debug::Log << "PRIVMSG: msgToUser: " << user->getNickname() << std::endl;

	std::string source = message.getSender()->getNickname();

	std::string params = user->getNickname() + " :" + message.getParamList()[1];

	Message newmessage(source, "PRIVMSG", params);
	newmessage.addDestinator(user);
	this->_callback.addMessage(newmessage);
}

void		Privmsg::msgToChannel(Channel *channel, Message& message) {
	Debug::Log << "PRIVMSG: msgToChannel: " << channel->get_name() << std::endl;

	std::string source = message.getSender()->getNickname();

	std::string params = channel->get_name() + " :" + message.getParamList()[1];

	Message newmessage(source, "PRIVMSG", params);

	channel->addDestinatorsExceptOneInMessage(message.getSender(), newmessage);
	this->_callback.addMessage(newmessage);
}