#ifndef ERR_NOSUCHSERVER_HPP
# define ERR_NOSUCHSERVER_HPP

# include "AReply.hpp"

class ERR_Nosuchserver : public AReply{
	private:

	public:
		ERR_Nosuchserver() : AReply("ERR_NOSUCHSERVER") {};
		~ERR_Nosuchserver() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string replyparam = message.getSender()->getNickname() + " " + param + " :No such server";

			Message newmessage(hub.getServerName(), "402", replyparam);
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
