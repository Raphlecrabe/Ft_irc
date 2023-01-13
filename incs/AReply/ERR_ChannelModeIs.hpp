#ifndef ERR_CHANNELMODEIS_HPP
# define ERR_CHANNELMODEIS_HPP

# include "AReply.hpp"

class ERR_ChannelModeIs : public AReply{
	private:

	public:
		ERR_ChannelModeIs() : AReply("ERR_CHANNELMODEIS") {};
		~ERR_ChannelModeIs() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			Channel *channel = hub.getChannelByName(param);

			std::string msgparams = channel->get_name() + " " + channel->getModestring() + " " + channel->getModearguments();
			Message newmessage(hub.getServerName(), "324", msgparams);

			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif