#include "../../incs/AReply/ERR_Toomanychannels.hpp"


ERR_Toomanychannels::ERR_Toomanychannels() : AReply("ERR_TOOMANYCHANNELS") {

}

ERR_Toomanychannels::~ERR_Toomanychannels() {
	
}

//Cette ERR a besoin du nom de channel en param
Message ERR_Toomanychannels::getmsg(Hub &hub, Message &message, std::string param)
{
	std::string	messageparam = message.getSender()->getName() + " " + param + " :You have joined too many channels";
	Message	newmessage(hub.getServerName(), "405", messageparam);
	return (newmessage);
}
