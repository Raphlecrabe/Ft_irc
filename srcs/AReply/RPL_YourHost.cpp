#include "../../incs/AReply/RPL_YourHost.hpp"


RPL_YourHost::RPL_YourHost() : AReply("RPL_YOURHOST") {

}

RPL_YourHost::~RPL_YourHost() {
	
}

Message RPL_YourHost::getmsg(Hub &hub, Message message) {
	std::string client = message.getSender()->getNickname();

	std::string params = client + " :Your host is " + hub.getServerName() + ", running version1";

	Message	newmessage(hub.getServerName(), "002", params);
	
	newmessage.destinator = message.getSender();

	return (newmessage);
}
