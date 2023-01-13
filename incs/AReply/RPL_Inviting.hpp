#ifndef RPL_INVITING_HPP
# define RPL_INVITING_HPP

# include "AReply.hpp"

class RPL_Inviting : public AReply{
	private:

	public:
		RPL_Inviting() : AReply("RPL_INVITING") {};
		~RPL_Inviting() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			Log();

			std::string params = message.getSender()->getNickname() + " " + param;
			Message newmessage(hub.getServerName(), "341", params);
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif
