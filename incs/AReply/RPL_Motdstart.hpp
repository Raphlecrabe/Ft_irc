#ifndef RPL_MOTDSTART_HPP
# define RPL_MOTDSTART_HPP

# include "AReply.hpp"

class RPL_Motdstart : public AReply{
	private:

	public:
		RPL_Motdstart() : AReply("RPL_MOTDSTART") {};
		~RPL_Motdstart() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)param;

			std::string msgparams = message.getSender()->getNickname() + " :- " + hub.getServerName() + " Message of the day - ";

			Message newmessage(hub.getServerName(), "375", msgparams);
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
