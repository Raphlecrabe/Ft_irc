#include "../../incs/AReply/ERR_Badchanmask.hpp"


ERR_Badchanmask::ERR_Badchanmask() : AReply("ERR_BADCHANMASK") {

}

ERR_Badchanmask::~ERR_Badchanmask() {
	
}
//Le param de cette ERR est le nom du channel concerne
Message ERR_Badchanmask::getmsg(Hub &hub, Message &message, std::string param)
{
	(void)message;
	std::string	messageparam = param + " :Bad Channel Mask";
	Message	newmessage(hub.getServerName(), "476", messageparam);
	return (newmessage);
}
