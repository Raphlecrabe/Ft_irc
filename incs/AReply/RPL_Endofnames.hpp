#ifndef RPL_ENDOFNAMES_HPP
# define RPL_ENDOFNAMES_HPP

# include "AReply.hpp"

class RPL_Endofnames : public AReply{
	private:

	public:
		RPL_Endofnames() : AReply("RPL_ENDOFNAMES") {}
		~RPL_Endofnames() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {

			std::string	messageparam = message.getSender()->getNickname() + " " + param + " :End of /Names list";
			Message	newmessage(hub.getServerName(), "366", messageparam);
			newmessage.addDestinator(message.getSender());
			return (newmessage);
		}
};

#endif
