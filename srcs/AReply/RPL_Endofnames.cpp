#include "../../incs/AReply/RPL_Endofnames.hpp"


RPL_Endofnames::RPL_Endofnames() : AReply("RPL_ENDOFNAMES") {

}

RPL_Endofnames::~RPL_Endofnames() {
	
}

Message RPL_Endofnames::getmsg(Hub &hub, Message &message, std::string param) {

	std::string	messageparam = message.getSender()->getName() + " " + param + " :End of /Names list";
	Message	newmessage(hub.getServerName(), "366", messageparam);
	return (newmessage);
}
