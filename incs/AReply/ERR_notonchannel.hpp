#ifndef ERR_NOTONCHANNEL_HPP
# define ERR_NOTONCHANNEL_HPP

# include "AReply.hpp"

class ERR_notonchannel : public AReply{
	private:

	public:
		ERR_notonchannel() : AReply("ERR_NOTONCHANNEL") {}
		~ERR_notonchannel() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string messageparam;

			messageparam += message.getSender()->getName() + " " + param + " :You're not on this channel";
			Message newmessage(hub.getServerName(), "442", messageparam);
			newmessage.addDestinator(message.getSender());
			return(newmessage);
		}
};

#endif
