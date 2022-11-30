#include "../../incs/AReply/Err_needmoreparams.hpp"


Err_needmoreparams::Err_needmoreparams() : AReply("ERR_NEEDMOREPARAMS") {

}

Err_needmoreparams::~Err_needmoreparams() {
	
}

Message Err_needmoreparams::getmsg(Hub &hub, Message &message) {
	std::string params;
	(void)hub;

	params += message.getSource() + " ";
	params += message.getCommand();
	params += " :Not enough parameters";
	
	Message	newmessage(":lebestserver.com", "461", params);

	newmessage.destinator = message.getSender();
	answer = newmessage;
	return (answer);
}