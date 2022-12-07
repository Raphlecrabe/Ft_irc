#ifndef ERR_TOOMANYCHANNELS_HPP
# define ERR_TOOMANYCHANNELS_HPP

# include "AReply.hpp"

class ERR_Toomanychannels : public AReply{
	private:

	public:
		ERR_Toomanychannels() : AReply("TOOMANYCHANNELS") {}
		~ERR_Toomanychannels() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string	messageparam = message.getSender()->getName() + " " + param + " :You have joined too many channels";
			Message	newmessage(hub.getServerName(), "405", messageparam);
			return (newmessage);
		}
};

#endif
