#ifndef ERR_CHANNELISFULL_HPP
# define ERR_CHANNELISFULL_HPP

# include "AReply.hpp"

class ERR_Channelisfull : public AReply{
	private:

	public:
		ERR_Channelisfull() : AReply("ERR_CHANNELISFULL") {}
		~ERR_Channelisfull() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string messageparam = message.getSender()->getNickname() + " " + param + " :Cannot join channel (+l)";
			Message	newmessage(hub.getServerName(), "471", messageparam);
			newmessage.addDestinator(message.getSender());
			return (newmessage);
		}
};

#endif
