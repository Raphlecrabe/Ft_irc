#include "../../incs/AReply/ERR_needmoreparams.hpp"


ERR_needmoreparams::ERR_needmoreparams() : AReply("ERR_NEEDMOREPARAMS") {

}

ERR_needmoreparams::~ERR_needmoreparams() {
	
}

Message ERR_needmoreparams::getmsg(Hub &hub, Message &message, std::string param) {
	std::string params;
	(void)hub;
	(void)param;

	params += message.getSource() + " ";
	params += message.getCommand();
	params += " :Not enough parameters";
	
	Message	newmessage(":lebestserver.com", "461", params);

	newmessage.addDestinator(message.getSender());
	return (newmessage);
}