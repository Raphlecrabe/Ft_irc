#include "../../incs/ACommand/Mode.hpp"

Mode::Mode() : ACommand("MODE"){

}

Mode::~Mode() {
	
}

Callback	&Mode::cmdExecute(Message & message, Hub & hub)
{
	Debug::Logstream << "MODE parameters given : " << message.getParams() << std::endl;
	std::vector<std::string> const paramlist = message.getParamList();
	Channel *channel = hub.getChannelByName(paramlist[0]);

	if (channel == NULL)
	{
		this->_callback.addReply("ERR_NOSUCHCHANNEL", paramlist[0]);
		return this->_callback;
	}

	if (paramlist.size() <= 1)
	{
		std::string channelModeParam = channel->get_name() + " " + channel->getModestring() + " " + channel->getModearguments();
		this->_callback.addReply("RPL_CHANNELMODEIS", channelModeParam);
		return this->_callback;
	}

	// if (message.getSender()->isNotAnOperator())
	// {
	// 	this->_callback.addReply("ERR_CHANOPRIVSNEEDED", channel->getName());
	// 	return this->_callback;
	// }

	char modeset = paramlist[1][0];
	std::string modeflags = paramlist[1].substr(1, paramlist[1].length() - 1);
	std::string modeparams = paramlist[2];

	this->executeModes(modeset, modeflags, modeparams, channel);

	return this->_callback;
}

void		Mode::executeModes(char modeset, std::string modeflags, std::string const modeparam, Channel *channel) {
	int len = modeflags.length();
	
	for (int i = 0; i < len; i++)
	{
		Debug::Logstream << "Checking mode " << modeflags[i] << "..." << std::endl;

	 	if (modeflags[i] == 'l')
		{
			int limit = Utils::toInt(modeparam);
			Debug::Logstream << "Executing mode 'l' with limit " << limit << " on channel " << channel->get_name() << std::endl;
			this->clientLimitChannel(modeset, limit, channel);
			continue;
		}

		//this->_callback.addReply("ERR_UMODEUNKNOWNFLAG", modeflags[i]);	ONLY APPLIES FOR USER MODE ?
	}
}

void		Mode::clientLimitChannel(char modeset, int limit, Channel *channel) {
	if (modeset == '-')
	{
		channel->RemoveClientLimit();
		return;
	}
	
	channel->SetClientLimit(limit);
}