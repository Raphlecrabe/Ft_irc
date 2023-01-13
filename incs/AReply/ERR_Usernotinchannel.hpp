#ifndef ERR_USERNOTINCHANNEL_HPP
# define ERR_USERNOTINCHANNEL_HPP

# include "AReply.hpp"

class ERR_Usernotinchannel : public AReply{
	private:

	public:
		ERR_Usernotinchannel() : AReply("ERR_USERNOTINCHANNEL") {};
		~ERR_Usernotinchannel() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			Log();

			std::string replyparam = message.getSender()->getNickname() + " " + param + " :They aren't on that channel";
			Message newmessage(hub.getServerName(), "441", replyparam);

			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif
