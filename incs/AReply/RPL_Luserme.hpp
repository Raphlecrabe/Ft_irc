#ifndef RPL_LUSERME_HPP
# define RPL_LUSERME_HPP

# include "AReply.hpp"

class RPL_Luserme : public AReply{
	private:

	public:
		RPL_Luserme() : AReply("RPL_LUSERME") {};
		~RPL_Luserme() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;
		
			int c = hub.getUserList().size();

			std::string params = message.getSender()->getNickname() + " :I have " + Utils::toString(c) + " clients and 0 servers";

			Message newmessage(hub.getServerName(), "255", params);
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
