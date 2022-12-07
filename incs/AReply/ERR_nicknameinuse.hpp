#ifndef ERR_NICKNAMEINUSE_HPP
# define ERR_NICKNAMEINUSE_HPP

# include "AReply.hpp"

class ERR_nicknameinuse : public AReply{
	private:

	public:
		ERR_nicknameinuse() : AReply("ERR_NICKNAMEINUSE") {}
		~ERR_nicknameinuse() {}

		Message	getmsg(Hub &hub, Message &message, std::string param)  {
			std::string params;
			(void)hub;
			(void)param;

			params += message.getSource() + " ";
			params += message.getSender()->getNickname();
			params += " :Nickname is already in use";

			Message	newmessage(":lebestserver.com", "433", params);

			newmessage.addDestinator(message.getSender());
			return (newmessage);
		}
};

#endif