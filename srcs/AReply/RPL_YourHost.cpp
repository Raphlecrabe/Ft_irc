#include "../../incs/AReply/RPL_YourHost.hpp"


RPL_YourHost::RPL_YourHost() : AReply("RPL_YOURHOST") {

}

RPL_YourHost::~RPL_YourHost() {
	
}

Message RPL_YourHost::getmsg(Hub &hub, Message message) {
	Message	newmessage(":lebestserver.com", "002", "fbelthoi :Your host is lebestserver.com, running version1");
	(void) hub;
	(void) message;

	newmessage.destinator = message.getSender();

	return (newmessage);
}
