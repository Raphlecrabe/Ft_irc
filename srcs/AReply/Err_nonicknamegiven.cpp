#include "../../incs/AReply/Err_nonicknamegiven.hpp"


Err_nonicknamegiven::Err_nonicknamegiven() : AReply("ERR_NONICKNAMEGIVEN") {

}

Err_nonicknamegiven::~Err_nonicknamegiven() {
	
}

Message Err_nonicknamegiven::getmsg(Hub &hub, Message &message) {
	std::string params;
	(void)hub;

	params += message.getSource();
	params += " :No nickname given";
	
	Message	newmessage(":lebestserver.com", "431", params);

	newmessage.destinator = message.getSender();
	answer = newmessage;
	return (answer);
}