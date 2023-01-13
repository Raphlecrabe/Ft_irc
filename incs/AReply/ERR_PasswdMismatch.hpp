#ifndef ERR_PASSWDMISMATCH_HPP
# define ERR_PASSWDMISMATCH_HPP

# include "AReply.hpp"

class ERR_PasswdMismatch : public AReply{
	private:

	public:
		ERR_PasswdMismatch() : AReply("ERR_PASSWDMISMATCH") {};
		~ERR_PasswdMismatch() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			param += "";

			std::string msgparam = message.getSender()->getName() + " :Password incorrect";

			Message newmessage(hub.getServerName(), "464", msgparam);
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif