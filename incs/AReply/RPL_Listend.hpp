#ifndef RPL_LISTEND_HPP
# define RPL_LISTEND_HPP

# include "AReply.hpp"

class RPL_Listend : public AReply{
	private:

	public:
		RPL_Listend() : AReply("RPL_LISTEND") {};
		~RPL_Listend() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			Log();
			(void)param;

			std::string messageparam = message.getSender()->getNickname() + " :End of /List";

			Message	newmessage(hub.getServerName(), "323", messageparam);
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif
