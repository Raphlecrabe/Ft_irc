#include "../../incs/AReply/Err_erroneusnickname.hpp"


Err_erroneusnickname::Err_erroneusnickname() : AReply("ERR_ERRONEUSNICKNAME") {

}

Err_erroneusnickname::~Err_erroneusnickname() {
	
}

Message &Err_erroneusnickname::getmsg(Hub &hub, Message &message) {
	std::string params;
	(void)hub;

	params += message.getSource() + " ";
	params += message.getSender()->getNickname();
	params += " :Erroneus nickname";
	
	Message	newmessage(":lebestserver.com", "432", params);

	newmessage.destinator = message.getSender();
	answer = newmessage;
	return (answer);
}