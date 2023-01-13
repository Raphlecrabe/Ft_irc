#ifndef ERR_PASSWDMISMATCH_HPP
# define ERR_PASSWDMISMATCH_HPP

# include "AReply.hpp"

class ERR_Passwdmismatch : public AReply{
	private:

	public:
		ERR_Passwdmismatch() : AReply("ERR_PASSWDMISMATCH") {};
		~ERR_Passwdmismatch() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;

			std::string messageparam = message.getSender()->getNickname() + " :Password incorrect";
			Message newmessage(hub.getServerName(), "464", messageparam);

			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
