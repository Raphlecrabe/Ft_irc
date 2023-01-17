#ifndef RPL_UMODEIS_HPP
# define RPL_UMODEIS_HPP

# include "AReply.hpp"

class RPL_UModeIs : public AReply{
	private:

	public:
		RPL_UModeIs() : AReply("RPL_UMODEIS") {};
		~RPL_UModeIs() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;

			Message newmessage(hub.getServerName(), "221", message.getSender()->getNickname() + " ");
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif