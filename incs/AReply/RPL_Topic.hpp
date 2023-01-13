#ifndef RPL_TOPIC_HPP
# define RPL_TOPIC_HPP

# include "AReply.hpp"

class RPL_Topic : public AReply{
	private:

	public:
		RPL_Topic() : AReply("RPL_TOPIC") {}
		~RPL_Topic() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			Channel	*channel = hub.getChannelByName(param);
			std::string messageparam = message.getSender()->getNickname();
			if (channel->get_topic().empty() == true)
			{
				messageparam += " " + channel->get_name() + " :No Topic is set";
				Message	NewMessageNoTopic(hub.getServerName(), "331", messageparam);
				NewMessageNoTopic.addDestinator(message.getSender());
				return (NewMessageNoTopic);
			}

			messageparam = message.getSender()->getNickname();
			messageparam += " " + channel->get_name() + " :" + channel->get_topic();
			Message	NewMessageTopic(hub.getServerName(), "332", messageparam);
			NewMessageTopic.addDestinator(message.getSender());
			return (NewMessageTopic);
		}
};

#endif
