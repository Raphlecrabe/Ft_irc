#ifndef RPL_INFO_HPP
# define RPL_INFO_HPP

# include "AReply.hpp"

class RPL_Info : public AReply{
	private:

	public:
		RPL_Info() : AReply("RPL_INFO") {};
		~RPL_Info() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			Log();

			(void)param;
			std::string messageparam = message.getSender()->getNickname() + " : You are using the Sausage IRC server, this is the first version of it, made by 2 moron";
			Message newmessage(hub.getServerName(), "371", messageparam);

			return newmessage;
		}
};

#endif
