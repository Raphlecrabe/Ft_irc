#include "../../incs/ACommand/Privmsg.hpp"

Privmsg::Privmsg() : ACommand("PRIVMSG"){

}

Privmsg::~Privmsg() {
	
}

Callback	&Privmsg::cmdExecute(Message & message, Hub & hub) {
	std::string target = message.getParamList()[0];

	// bool OPER = false;
	// if (target[0] == '@')
	// {
	// 	OPER = true;
	// 	target = target.substr(1, target.length - 1);
	// }
	
	User *destinator = hub.get_UserByNickName(target);
	if (destinator)
		msgToUser(destinator, message);
	else {
		Channel *channel = hub.getChannelByName(target);
		if (channel)
			msgToChannel(channel, message);
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
	if (channel->get_users().size() <= 1)
		return;

	channel->addDestinatorsExceptOneInMessage(message.getSender(), newmessage);
	this->_callback.addMessage(newmessage);
}