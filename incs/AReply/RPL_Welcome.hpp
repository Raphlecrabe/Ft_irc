#ifndef RPL_WELCOME_HPP
# define RPL_WELCOME_HPP

# include "AReply.hpp"

# include <iostream>

class RPL_Welcome : public AReply {
	private:

	public:
		RPL_Welcome() : AReply("RPL_WELCOME") {}
		~RPL_Welcome() {}

		Message getmsg(Hub &hub, Message &message, std::string param) {

			(void)param;

			std::string client = message.getSender()->getNickname();
			std::string nick = message.getSender()->getNickname();

			std::string params = client + " :Welcome to the " + hub.getNetworkName() + " Network, " + nick;

			Message	newmessage(hub.getServerName(), "001", params);
			(void) message;

			newmessage.addDestinator(message.getSender());

			return (newmessage);
		}
};

#endif