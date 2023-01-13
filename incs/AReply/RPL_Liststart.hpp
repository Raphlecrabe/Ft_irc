#ifndef RPL_LISTSTART_HPP
# define RPL_LISTSTART_HPP

# include "AReply.hpp"

class RPL_Liststart : public AReply{
	private:

	public:
		RPL_Liststart() : AReply("RPL_LISTSTART") {};
		~RPL_Liststart() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;
			std::string messageparam = message.getSender()->getNickname() + " Channel :Users Name";

			Message	newmessage(hub.getServerName(), "321", messageparam);
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif
