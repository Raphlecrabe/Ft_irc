#include "../../incs/AReply/Err_nicknameinuse.hpp"


Err_nicknameinuse::Err_nicknameinuse() : AReply("ERR_NICKNAMEINUSE") {

}

Err_nicknameinuse::~Err_nicknameinuse() {
	
}

Message Err_nicknameinuse::getmsg(Hub &hub, Message &message) {
	std::string params;
	(void)hub;

	params += message.getSource() + " ";
	params += message.getSender()->getNickname();
	params += " :Nickname is already in use";
	
	Message	newmessage(":lebestserver.com", "433", params);

	newmessage.destinator = message.getSender();
	answer = newmessage;
	return (answer);
}