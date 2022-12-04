#include "../../incs/AReply/RPL_MyInfo.hpp"


RPL_MyInfo::RPL_MyInfo() : AReply("RPL_MYINFO") {

}

RPL_MyInfo::~RPL_MyInfo() {
	
}

Message RPL_MyInfo::getmsg(Hub &hub, Message &message) {
	std::string log = getName() + " called";
	Debug::Log(log);

	std::string client = message.getSender()->getNickname();

	std::string params = client + " " + hub.getServerName() + " 1.0";

	Message	newmessage(hub.getServerName(), "004", params);

	newmessage.addDestinator(message.getSender());

	return (newmessage);
}