#ifndef ERR_NOPRIVILEGES_HPP
# define ERR_NOPRIVILEGES_HPP

# include "AReply.hpp"

class ERR_NOPRIVILEGES : public AReply{
	private:

	public:
		ERR_NOPRIVILEGES() : AReply("ERR_NOPRIVILEGES") {};
		~ERR_NOPRIVILEGES() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {

			(void)param;
			std::string messageparam = message.getSender()->getNickname() + " :Permission Denied- You're not an IRC operator";
			Message newmessage(hub.getServerName(), "481", messageparam);
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif