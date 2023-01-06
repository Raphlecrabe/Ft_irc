#ifndef ERR_NEEDMOREPARAMS_HPP
# define ERR_NEEDMOREPARAMS_HPP

# include "AReply.hpp"

class ERR_needmoreparams : public AReply{
	private:

	public:
		ERR_needmoreparams() : AReply("ERR_NEEDMOREPARAMS") {}
		~ERR_needmoreparams() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string params;
			(void)hub;
			(void)param;

			params += message.getSender()->getNickname() + " ";
			params += message.getCommand();
			params += " :Not enough parameters";
			
			Message	newmessage(":lebestserver.com", "461", params);

			newmessage.addDestinator(message.getSender());
			return (newmessage);
		}
};

#endif