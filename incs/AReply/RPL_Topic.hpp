#ifndef RPL_TOPIC_HPP
# define RPL_TOPIC_HPP

# include "AReply.hpp"

class RPL_Topic : public AReply{
	private:

	public:
		RPL_Topic() : AReply("RPL_TOPIC") {}
		~RPL_Topic() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
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
};

#endif
