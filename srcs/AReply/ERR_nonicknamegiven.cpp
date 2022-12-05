#include "../../incs/AReply/ERR_nonicknamegiven.hpp"


ERR_nonicknamegiven::ERR_nonicknamegiven() : AReply("ERR_NONICKNAMEGIVEN") {

}

ERR_nonicknamegiven::~ERR_nonicknamegiven() {
	
}

Message ERR_nonicknamegiven::getmsg(Hub &hub, Message &message, std::string param) {
	std::string params;
	(void)hub;
	(void)param;

	params += message.getSource();
	params += " :No nickname given";
	
	Message	newmessage(hub.getServerName(), "431", params);

	newmessage.addDestinator(message.getSender());
	return (newmessage);
}