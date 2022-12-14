#ifndef PASSWDMISMATCH_HPP
# define PASSWDMISMATCH_HPP

# include "AReply.hpp"

class PasswdMismatch : public AReply{
	private:

	public:
		PasswdMismatch() : AReply("PASSWDMISMATCH") {};
		~PasswdMismatch() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;
			
			Message newmessage(hub.getServerName(), "464", ":Password incorrect");
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
