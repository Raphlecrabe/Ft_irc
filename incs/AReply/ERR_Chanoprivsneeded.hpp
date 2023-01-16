#ifndef ERR_CHANOPRIVSNEEDED_HPP
# define ERR_CHANOPRIVSNEEDED_HPP

# include "AReply.hpp"

class ERR_Chanoprivsneeded : public AReply{
	private:

	public:
		ERR_Chanoprivsneeded() : AReply("ERR_CHANOPRIVSNEEDED") {};
		~ERR_Chanoprivsneeded() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string replyparam = message.getSender()->getNickname() + " " + param + " :You are not a channel operator";
			Message newmessage(hub.getServerName(), "482", replyparam);

			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif