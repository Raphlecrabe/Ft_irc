#ifndef RPL_MOTD_HPP
# define RPL_MOTD_HPP

# include "AReply.hpp"

class RPL_Motd : public AReply{
	private:

	public:
		RPL_Motd() : AReply("RPL_MOTD") {};
		~RPL_Motd() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;

			std::string msgparams = message.getSender()->getNickname() + " :" + *(hub.getMessageOfTheDay());

			Message newmessage(hub.getServerName(), "372", msgparams);
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
