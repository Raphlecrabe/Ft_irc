#include "../../incs/AReply/RPL_IsSupport.hpp"


RPL_IsSupport::RPL_IsSupport() : AReply("RPL_ISSUPPORT") {

}

RPL_IsSupport::~RPL_IsSupport() {
	
}

Message RPL_IsSupport::getmsg(Hub &hub, Message &message) {
	std::string log = getName() + " called";
	Debug::Log(log);

	std::string client = message.getSender()->getNickname();

	std::string params = client + " AWAYLEN=200" + " :are supported by this server";

	Message	newmessage(hub.getServerName(), "005", params);

	newmessage.addDestinator(message.getSender());

	return (newmessage);
}