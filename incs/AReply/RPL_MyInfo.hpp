#ifndef RPL_MYINFO_HPP
# define RPL_MYINFO_HPP

# include "AReply.hpp"

class RPL_MyInfo : public AReply{
	private:

	public:
		RPL_MyInfo() : AReply("RPL_MYINFO") {}
		~RPL_MyInfo() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {

			(void)param;

			std::string client = message.getSender()->getNickname();

			std::string params = client + " " + hub.getServerName() + " 1.0";

			Message	newmessage(hub.getServerName(), "004", params);

			newmessage.addDestinator(message.getSender());

			return (newmessage);
		}
};

#endif