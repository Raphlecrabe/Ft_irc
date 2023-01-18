#include "../../incs/ACommand/Notice.hpp"

Notice::Notice() : ACommand("NOTICE"){

}

Notice::~Notice() {
	
}

Callback	&Notice::cmdExecute(Message & message, Hub & hub)
{
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
	}
	return this->_callback;
}

void		Notice::msgToUser(User *user, Message& message) {
	Debug::Log << "NOTICE: msgToUser: " << user->getNickname() << std::endl;

	std::string source = message.getSender()->getNickname();

	std::string params = user->getNickname() + " :" + message.getParamList()[1];

	Message newmessage(source, "PRIVMSG", params);
	newmessage.addDestinator(user);
	this->_callback.addMessage(newmessage);
}

void		Notice::msgToChannel(Channel *channel, Message& message) {
	Debug::Log << "NOTICE: msgToChannel: " << channel->get_name() << std::endl;

	std::string source = message.getSender()->getNickname();

	std::string params = channel->get_name() + " :" + message.getParamList()[1];

	Message newmessage(source, "PRIVMSG", params);

	channel->addDestinatorsExceptOneInMessage(message.getSender(), newmessage);
	this->_callback.addMessage(newmessage);
}