#ifndef RPL_CHANNELMODEIS_HPP
# define RPL_CHANNELMODEIS_HPP

# include "AReply.hpp"

class RPL_ChannelModeIs : public AReply {
	private:

	public:
		RPL_ChannelModeIs() : AReply("RPL_CHANNELMODEIS") {};
		~RPL_ChannelModeIs() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			User *user = message.getSender();
			Channel *channel = hub.getChannelByName(param);

			std::string msgparams = user->getNickname() + " " + channel->get_name() + " " + channel->getModestring() + " " + channel->getModearguments();
			Message newmessage(hub.getServerName(), "324", msgparams);

			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif