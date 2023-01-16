#ifndef ERROR_HPP
# define ERROR_HPP

# include "AReply.hpp"

class Error : public AReply{
	private:

	public:
		Error() : AReply("ERROR") {};
		~Error() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			param = ":" + param;
			Message newmessage(hub.getServerName(), "ERROR", param);
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif