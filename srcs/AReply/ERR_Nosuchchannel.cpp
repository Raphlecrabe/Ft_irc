#include "../../incs/AReply/ERR_Nosuchchannel.hpp"


ERR_Nosuchchannel::ERR_Nosuchchannel() : AReply("ERR_NOSUCHCHANNEL") {

}

ERR_Nosuchchannel::~ERR_Nosuchchannel() {
	
}
//Le param de cette RPL doit etre le nom du channel concerne
Message ERR_Nosuchchannel::getmsg(Hub &hub, Message &message, std::string param) 
{
	std::string messageparam;

	messageparam += message.getSender()->getName() + " " + param + " :No such channel";
	Message newmessage(hub.getServerName(), "403", messageparam);
	newmessage.addDestinator(message.getSender());
	return(newmessage);
}
