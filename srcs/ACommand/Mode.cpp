#include "../../incs/ACommand/Mode.hpp"

Mode::Mode() : ACommand("MODE"){

}

Mode::~Mode() {
	
}

Callback	&Mode::cmdExecute(Message & message, Hub & hub)
{
	Debug::Log<< "MODE called, parameters : " << message.getParams() << std::endl;
	std::vector<std::string> const paramlist = message.getParamList();
	Channel *channel = hub.getChannelByName(paramlist[0]);

	if (channel == NULL)
	{
		this->_callback.addReply("ERR_NOSUCHCHANNEL", paramlist[0]);
		return this->_callback;
	}

	if (paramlist.size() <= 1)
	{
		this->_callback.addReply("RPL_CHANNELMODEIS", paramlist[0]);
		return this->_callback;
	}

	if (channel->isChannelOperator(message.getSender()) == 0) // check if irc operator? hub.isIrcOperator(message.getSender())
	{
		this->_callback.addReply("ERR_CHANOPRIVSNEEDED", channel->get_name());
		return this->_callback;
	}

	char modeset = paramlist[1][0];
	std::string modeflags = paramlist[1].substr(1, paramlist[1].length() - 1);

	if (paramlist.size() <= 2)
		return this->_callback;

	std::string modeparams = paramlist[2];

	this->executeModes(modeset, modeflags, modeparams, channel);

	return this->_callback;
}

void		Mode::executeModes(char modeset, std::string modeflags, std::string const modeparam, Channel *channel) {
	int len = modeflags.length();
	
	for (int i = 0; i < len; i++)
	{
		Debug::Log << "Checking mode " << modeflags[i] << "..." << std::endl;

	 	if (modeflags[i] == 'l')
		{
			int limit = Utils::toInt(modeparam);
			Debug::Log << "Executing mode 'l' with limit " << limit << " on channel " << channel->get_name() << std::endl;
			this->clientLimitChannel(modeset, limit, channel);
			break;
		}
	}
}

void		Mode::clientLimitChannel(char modeset, int limit, Channel *channel) {
	if (modeset == '-')
	{
		channel->RemoveClientLimit();
		return;
	}
	
	channel->SetClientLimit(limit);

	// Send the MODE command to all users of the channel
	// std::string params = modeset + 'l' + " " + Utils::toString(limit);
	// Message *msg = new Message(hub.getServerName(), "MODE", params);;
	// channel->sendToAllUsers(channel, Message);
	// delete msg;
}