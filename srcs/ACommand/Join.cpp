#include "../../incs/ACommand/Join.hpp"

//TO DO Checker si ca marche

Join::Join() : ACommand("JOIN"){

}

Join::~Join() {
	
}

int	Join::checkparams(Message &message)
{
	if (message.getParamList().size() == 0)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS");
		return (-1);
	}
	return (0);
}

int	Join::joinChannel(Channel *channel, Message &message, std::string param)
{
	if (channel->AddUser(message.getSender()) == -1)
	{
		_callback.addReply("ERR_CHANNELISFULL", param);
		return (-1);
	}
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
		hub.CreateChannel(param, message.getSender());
	}
	catch(const std::exception &e)
	{
		_callback.addReply(e.what(), param);
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
	std::vector<std::string> params = Utils::split(message.getParamList()[0], ',');

	for (unsigned int i = 0; i < params.size(); i++)
	{
		if (params[i].size() == 0)
			continue;
		Channel	*channel = hub.getChannelByName(params[i]);
		if (channel == NULL)
		{
			if (addChannel(hub, message, params[i]) == -1)
				continue;
			channel = hub.getChannelByName(params[i]);
			//Debug
			std::string log = "Join : adding a new channel " + params[i];
			Debug::Log(log);
			continue;
		}
		if (joinChannel(channel, message, params[i]) == -1)
			continue;
		//Debug
		std::string log = "Join : Joined a new channel " + params[i];
		Debug::Log(log);
	}
	return(_callback);
}