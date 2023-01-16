#ifndef ERR_ALREADYREGISTERED_HPP
# define ERR_ALREADYREGISTERED_HPP

# include "AReply.hpp"

class ERR_AlreadyRegistered : public AReply{
	private:

	public:
		ERR_AlreadyRegistered() : AReply("ERR_ALREADYREGISTERED") {};
		~ERR_AlreadyRegistered() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			param = message.getSender()->getNickname() + ": You may not reregister";

			Message newmessage(hub.getServerName(), "462", param);
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif