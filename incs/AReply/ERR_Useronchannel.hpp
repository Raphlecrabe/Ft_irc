#ifndef ERR_USERONCHANNEL_HPP
# define ERR_USERONCHANNEL_HPP

# include "AReply.hpp"

class ERR_Useronchannel : public AReply{
	private:

	public:
		ERR_Useronchannel() : AReply("ERR_USERONCHANNEL") {};
		~ERR_Useronchannel() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string params = message.getSender()->getNickname() + param + " :is already on channel";
			Message newmessage(hub.getServerName(), "443", params);
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
