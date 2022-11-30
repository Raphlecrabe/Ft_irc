#include "../../incs/AReply/ERR_nicknameinuse.hpp"


ERR_nicknameinuse::ERR_nicknameinuse() : AReply("ERR_NICKNAMEINUSE") {

}

ERR_nicknameinuse::~ERR_nicknameinuse() {
	
}

Message ERR_nicknameinuse::getmsg(Hub &hub, Message &message, std::string &param) {
	std::string params;
	(void)hub;
	(void)param;

	params += message.getSource() + " ";
	params += message.getSender()->getNickname();
	params += " :Nickname is already in use";
	
	Message	newmessage(":lebestserver.com", "433", params);

	newmessage.addDestinator(message.getSender());
	return (newmessage);
}