#ifndef RPL_ENDOFINFO_HPP
# define RPL_ENDOFINFO_HPP

# include "AReply.hpp"

class RPL_Endofinfo : public AReply{
	private:

	public:
		RPL_Endofinfo() : AReply("RPL_ENDOFINFO") {};
		~RPL_Endofinfo() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;
			std::string messageparam = message.getSender()->getNickname() + " :End of info list";
			Message newmessage(hub.getServerName(), "374", messageparam);
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif
