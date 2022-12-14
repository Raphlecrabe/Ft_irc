#ifndef RPL_ENDOFMOTD_HPP
# define RPL_ENDOFMOTD_HPP

# include "AReply.hpp"

class RPL_Endofmotd : public AReply{
	private:

	public:
		RPL_Endofmotd() : AReply("RPL_ENDOFMOTD") {};
		~RPL_Endofmotd() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;

			Message newmessage(hub.getServerName(), "376", ":End of /MOTD command.");
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
