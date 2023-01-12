#ifndef ERR_CHANOPRIVSNEEDED_HPP
# define ERR_CHANOPRIVSNEEDED_HPP

# include "AReply.hpp"

class ERR_ChanoPrivsNeeded : public AReply{
	private:

	public:
		ERR_ChanoPrivsNeeded() : AReply("ERR_CHANOPRIVSNEEDED") {};
		~ERR_ChanoPrivsNeeded() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			param += " :You're not a channel operator";

			Message newmessage(hub.getServerName(), "482", param);

			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif