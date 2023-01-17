#ifndef RPL_LUSERCLIENT_HPP
# define RPL_LUSERCLIENT_HPP

# include "AReply.hpp"

class RPL_Luserclient : public AReply{
	private:

	public:
		RPL_Luserclient() : AReply("RPL_LUSERCLIENT") {};
		~RPL_Luserclient() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			
			(void)param;
			
			int	u = hub.getUserList().size();

			std::string params = message.getSender()->getNickname() + " :There are " + Utils::toString(u) + " users and 0 invisible on 1 servers";
			
			Message newmessage(hub.getServerName(), "251", params);
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
