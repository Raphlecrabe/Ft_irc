#ifndef ERR_BADCHANMASK_HPP
# define ERR_BADCHANMASK_HPP

# include "AReply.hpp"

class ERR_Badchanmask : public AReply{
	private:

	public:
		ERR_Badchanmask() : AReply("ERR_BADCHANMASK") {}
		~ERR_Badchanmask() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			(void)message;
			std::string	messageparam = param + " :Bad Channel Mask";
			Message	newmessage(hub.getServerName(), "476", messageparam);
			return (newmessage);
		}
};

#endif
