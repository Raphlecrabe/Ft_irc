#ifndef ERR_ERRONEUSNICKNAME_HPP
# define ERR_ERRONEUSNICKNAME_HPP

# include "AReply.hpp"

class ERR_erroneusnickname : public AReply{
	private:

	public:
		ERR_erroneusnickname() : AReply("ERR_ERRONEUSNICKNAME") { }
		~ERR_erroneusnickname() { }

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string params;
			(void)hub;
			(void)param;

			params += message.getSource() + " ";
			params += param;
			params += " :Erroneus nickname";

			Message	newmessage(hub.getServerName(), "432", params);

			newmessage.addDestinator(message.getSender());
			return (message);
		}
};

#endif