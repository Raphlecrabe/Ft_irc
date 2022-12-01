#include "../../incs/AReply/RPL_Namereply.hpp"


RPL_Namereply::RPL_Namereply() : AReply("RPL_NAMEREPLY") {

}

RPL_Namereply::~RPL_Namereply() {
	
}

//Le param de cette Reply est le nom du channel concerne
Message RPL_Namereply::getmsg(Hub &hub, Message &message, std::string param)
{
	Channel	*channel = hub.getChannelByName(param);

	std::string messageparam = message.getSender()->getName() + " =" + channel->get_name() + " :";
	std::vector<User *>channelusers = channel->get_users();
	std::vector<User *>::iterator it;
	for (it = channelusers.begin(); it != channelusers.end(); it++)
	{
		messageparam += (*it)->getNickname() + " ";
	}
	Message	newmessage(hub.getServerName(), "353", messageparam);
	newmessage.addDestinator(message.getSender());
	return (newmessage);
}
