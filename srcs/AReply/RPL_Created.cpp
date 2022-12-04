#include "../../incs/AReply/RPL_Created.hpp"


RPL_Created::RPL_Created() : AReply("RPL_CREATED") {

}

RPL_Created::~RPL_Created() {
	
}

Message RPL_Created::getmsg(Hub &hub, Message &message) {
	std::string log = getName() + " called";
	Debug::Log(log);

	std::string client = message.getSender()->getNickname();

	std::string params = client + " :This server was created " + hub.getStartTime();

	Message	newmessage(hub.getServerName(), "003", params);

	newmessage.addDestinator(message.getSender());

	return (newmessage);
}