#ifndef ERR_NOSUCHNICK_HPP
# define ERR_NOSUCHNICK_HPP

# include "AReply.hpp"

class ERR_NoSuchNick : public AReply{
	private:

	public:
		ERR_NoSuchNick() : AReply("ERR_NOSUCHNICK") {};
		~ERR_NoSuchNick() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string msgparam = message.getSender()->getNickname() + " " + param + " :No such nick";

			Message newmessage(hub.getServerName(), "401", msgparam);
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif