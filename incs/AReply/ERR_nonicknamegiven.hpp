#ifndef ERR_NONICKNAMEGIVEN_HPP
# define ERR_NONICKNAMEGIVEN_HPP

# include "AReply.hpp"

class ERR_nonicknamegiven : public AReply{
	private:

	public:
		ERR_nonicknamegiven() : AReply("ERR_NONICKNAMEGIVEN") {}
		~ERR_nonicknamegiven() {}

		Message	getmsg(Hub &hub, Message &message)  {
			std::string params;
			(void)hub;

			params += message.getSource();
			params += " :No nickname given";
			
			Message	newmessage(":lebestserver.com", "431", params);

			newmessage.addDestinator(message.getSender());
			return (newmessage);
		}
};

#endif