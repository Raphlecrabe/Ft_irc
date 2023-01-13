#ifndef RPL_YOUREOPER_HPP
# define RPL_YOUREOPER_HPP

# include "AReply.hpp"

class RPL_Youreoper : public AReply{
	private:

	public:
		RPL_Youreoper() : AReply("RPL_YOUREOPER") {};
		~RPL_Youreoper() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;

			std::string messageparam = message.getSender()->getNickname() +  " :You are now an IRC operator";
			Message newmessage(hub.getServerName(), "381", messageparam);

			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif
