#include "../../incs/AReply/ERR_notonchannel.hpp"


ERR_notonchannel::ERR_notonchannel() : AReply("ERR_NOTONCHANNEL") {

}

ERR_notonchannel::~ERR_notonchannel() {
	
}
//Cette rpl prend en parametre le channel concerne
Message ERR_notonchannel::getmsg(Hub &hub, Message &message, std::string param) 
{
	std::string messageparam;

	messageparam += message.getSender()->getName() + " " + param + " :You're not on this channel";
	Message newmessage(hub.getServerName(), "442", messageparam);
	newmessage.addDestinator(message.getSender());
	return(newmessage);
}
