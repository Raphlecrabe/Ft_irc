#include "../../incs/AReply/ERR_Channelisfull.hpp"


ERR_Channelisfull::ERR_Channelisfull() : AReply("ERR_CHANNELISFULL") {

}

ERR_Channelisfull::~ERR_Channelisfull() {
	
}

//Le param de cette RPL est le channel concerne
Message ERR_Channelisfull::getmsg(Hub &hub, Message &message, std::string param)
{
	std::string messageparam = message.getSender()->getName() + " " + param + " :Cannot join channel (+l)";
	Message	newmessage(hub.getServerName(), "471", messageparam);
	return (newmessage);
}
