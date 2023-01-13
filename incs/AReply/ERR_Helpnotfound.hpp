#ifndef ERR_HELPNOTFOUND_HPP
# define ERR_HELPNOTFOUND_HPP

# include "AReply.hpp"

class ERR_Helpnotfound : public AReply{
	private:

	public:
		ERR_Helpnotfound() : AReply("ERR_HELPNOTFOUND") {};
		~ERR_Helpnotfound() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;

			std::string messageparam = message.getSender()->getNickname() + " " + param
				+ " :No help found on this subject";
			Message newmessage(hub.getServerName(), "524", messageparam);

			return newmessage;
		}
};

#endif
