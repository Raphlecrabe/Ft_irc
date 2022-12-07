#ifndef ERR_NOSUCHCHANNEL_HPP
# define ERR_NOSUCHCHANNEL_HPP

# include "AReply.hpp"

class ERR_Nosuchchannel : public AReply{
	private:

	public:
		ERR_Nosuchchannel() : AReply("ERR_NOSUCHCHANNEL") {}
		~ERR_Nosuchchannel() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string messageparam;

			messageparam += message.getSender()->getName() + " " + param + " :No such channel";
			Message newmessage(hub.getServerName(), "403", messageparam);
			newmessage.addDestinator(message.getSender());
			return(newmessage);
		}
};

#endif
