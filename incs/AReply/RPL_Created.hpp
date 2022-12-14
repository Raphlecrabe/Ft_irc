#ifndef RPL_CREATED_HPP
# define RPL_CREATED_HPP

# include "AReply.hpp"

class RPL_Created : public AReply{
	private:

	public:
		RPL_Created(): AReply("RPL_CREATED") {}
		~RPL_Created() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {

			(void)param;

			std::string client = message.getSender()->getNickname();

			std::string params = client + " :This server was created " + hub.getStartTime();

			Message	newmessage(hub.getServerName(), "003", params);

			newmessage.addDestinator(message.getSender());

			return (newmessage);
		}
};

#endif