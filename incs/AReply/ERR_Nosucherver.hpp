#ifndef ERR_NOSUCHERVER_HPP
# define ERR_NOSUCHERVER_HPP

# include "AReply.hpp"

class ERR_Nosucherver : public AReply{
	private:

	public:
		ERR_Nosucherver() : AReply("ERR_NOSUCHERVER") {};
		~ERR_Nosucherver() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {

			Message newmessage(hub.getServerName(), "402", param + " :No such server");
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
