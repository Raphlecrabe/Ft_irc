#ifndef ERR_CHANNELMODEIS_HPP
# define ERR_CHANNELMODEIS_HPP

# include "AReply.hpp"

class ERR_ChannelModeIs : public AReply{
	private:

	public:
		ERR_ChannelModeIs() : AReply("ERR_CHANNELMODEIS") {};
		~ERR_ChannelModeIs() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {

			Message newmessage(hub.getServerName(), "324", param);

			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif