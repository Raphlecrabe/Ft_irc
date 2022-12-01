#include "../../incs/ACommand/Join.hpp"

Join::Join() : ACommand("JOIN"){

}

Join::~Join() {
	
}

int	Join::checkparams(Message &message)
{
	if (message.getParamList().size() == 0)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS", "");
		return (-1);
	}
	return (0);
}

int	Join::joinChannel(Channel *channel, Message &message, std::string param)
{
	if (channel->AddUser(*(message.getSender())) == -1)
	{
		_callback.addReply("ERR_CHANNELISFULL", param);
		return (-1);
	}
	channel->AddFd(message.getSender()->getFd());
	addReplys(param);
	Message newmessage(message.getSender()->getNickname(), "JOIN", channel->get_name());
	newmessage.addDestinator(message.getSender());
	channel->addDestinatorsExceptOneInMessage(message.getSender(), newmessage);
	return (0);
}

int	Join::addChannel(Hub &hub, Message &message, std::string &param)
{
	try
		{
			hub.CreateChannel(param, *message.getSender());
		}
		catch(const std::exception &e)
		{
			_callback.addReply(e.what(), "");
			return (-1);
		}
		addReplys(param);
		return (0);
}

void	Join::addReplys(std::string &param)
{
	_callback.addReply("RPL_TOPIC", param);
	_callback.addReply("RPL_NAMEREPLY", param);
	_callback.addReply("RPL_ENDOFNAMES", param);
}

Callback	&Join::cmdExecute(Message & message, Hub & hub)
{
	if (checkparams(message) == -1)
		return (_callback);
	std::vector<std::string> params = message.getParamList();
	for (unsigned int i = 0; i < message.getParamList().size(); i++)
	{
		Channel	*channel = hub.getChannelByName(params[i]);
		if (channel == NULL)
		{
			if (addChannel(hub, message, params[i]) == -1)
				continue;
		}
		if (joinChannel(channel, message, params[i]) == -1)
			continue;
	}
	return(_callback);
}