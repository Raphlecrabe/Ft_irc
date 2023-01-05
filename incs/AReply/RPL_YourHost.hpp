#ifndef RPL_YOURHOST_HPP
# define RPL_YOURHOST_HPP

# include "AReply.hpp"

class RPL_YourHost : public AReply{
	private:

	public:
		RPL_YourHost() : AReply("RPL_YOURHOST") {}
		~RPL_YourHost() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			Log();

			(void)param;

			std::string client = message.getSender()->getNickname();

			std::string params = client + " :Your host is " + hub.getServerName() + ", running version1";

			Message	newmessage(hub.getServerName(), "002", params);
			
			newmessage.addDestinator(message.getSender());

			return (newmessage);
		}
};

#endif
