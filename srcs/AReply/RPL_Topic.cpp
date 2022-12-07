#include "../../incs/AReply/RPL_Topic.hpp"


RPL_Topic::RPL_Topic() : AReply("RPL_TOPIC") {

}

RPL_Topic::~RPL_Topic() {
	
}
//Le Param de cette RPL est le non du channel concerné
Message RPL_Topic::getmsg(Hub &hub, Message &message, std::string param) {
	Message	NewMessageNoTopic("", "", "");
	Channel	*channel = hub.getChannelByName(param);
	if (channel->get_topic().empty() == 1)
		return (NewMessageNoTopic);

	std::string messageparam = message.getSender()->getName();
	messageparam += " " + channel->get_name() + " :" + channel->get_topic();
	Message	NewMessageTopic(hub.getServerName(), "332", messageparam);
	NewMessageTopic.addDestinator(message.getSender());
	return (NewMessageTopic);
}
