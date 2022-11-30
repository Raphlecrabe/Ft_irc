#include "../../incs/AReply/RPL_Welcome.hpp"
#include "../../incs/AReply/AReply.hpp"

RPL_Welcome::RPL_Welcome() : AReply("RPL_WELCOME") {

}

RPL_Welcome::~RPL_Welcome() {
	
}

Message RPL_Welcome::getmsg(Hub &hub, Message &message, std::string &param) {
	(void)param;
	std::string client = message.getSender()->getNickname();
	std::string nick = message.getSender()->getNickname();

	std::string params = client + " :Welcome to the " + hub.getNetworkName() + " Network, " + nick;

	Message	newmessage(hub.getServerName(), "001", params);
	(void) message;

	newmessage.addDestinator(message.getSender());

	return (newmessage);
}