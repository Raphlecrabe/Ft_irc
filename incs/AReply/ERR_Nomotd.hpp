#ifndef ERR_NOMOTD_HPP
# define ERR_NOMOTD_HPP

# include "AReply.hpp"

class ERR_Nomotd : public AReply{
	private:

	public:
		ERR_Nomotd() : AReply("ERR_NOMOTD") {};
		~ERR_Nomotd() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;

			Message newmessage(hub.getServerName(), "422", "Error :MOTD File is missing");
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
