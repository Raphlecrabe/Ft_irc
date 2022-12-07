#ifndef RPL_ISSUPPORT_HPP
# define RPL_ISSUPPORT_HPP

# include "AReply.hpp"

class RPL_IsSupport : public AReply{
	private:

	public:
		RPL_IsSupport() : AReply("RPL_ISSUPPORT") {}
		~RPL_IsSupport() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string log = getName() + " called";
			Debug::Log(log);

			std::string client = message.getSender()->getNickname();

			std::string params = client + " AWAYLEN=200" + " :are supported by this server";

			Message	newmessage(hub.getServerName(), "005", params);

			newmessage.addDestinator(message.getSender());

			return (newmessage);
		}
};

#endif