#include "../../incs/AReply/ERR_erroneusnickname.hpp"


ERR_erroneusnickname::ERR_erroneusnickname() : AReply("ERR_ERRONEUSNICKNAME") {

}

ERR_erroneusnickname::~ERR_erroneusnickname() {
	
}

Message ERR_erroneusnickname::getmsg(Hub &hub, Message &message, std::string param) {
	std::string params;
	(void)hub;
	(void)param;

	params += message.getSource() + " ";
	params += message.getSender()->getNickname();
	params += " :Erroneus nickname";
	
	Message	newmessage(":lebestserver.com", "432", params);

	newmessage.addDestinator(message.getSender());
	return (newmessage);
}