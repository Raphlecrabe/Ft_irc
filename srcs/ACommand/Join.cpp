#include "../../incs/ACommand/Join.hpp"

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

void Join::addJoinMsgToCallback(User *user, Channel *channel) {
	Message newmessage(user->getNickname(), "JOIN", channel->get_name());
	channel->addAllUsersToMessage(newmessage);
	_callback.addMessage(newmessage);
}

int	Join::joinChannel(Channel *channel, Message &message, std::string param)
{
	if (channel->AddUser(message.getSender()) == -1)
	{
		_callback.addReply("ERR_CHANNELISFULL", param);
		return (-1);
	}
	addReplys(param);
	addJoinMsgToCallback(message.getSender(), channel);
	Debug::Log << "JOIN: user: " << message.getSender()->getNickname() << " joined channel: " << channel->get_name() << std::endl;
	return (0);
}

int	Join::addChannel(Hub &hub, Message &message, std::string &param)
{
	try
	{
		Channel &channel = hub.CreateChannel(param, message.getSender());
		addJoinMsgToCallback(message.getSender(), &channel);
		Debug::Log << "JOIN: created channel: " << channel.get_name() << std::endl;
	}
	catch(const std::exception &e)
	{
		_callback.addReply(e.what(), param);
		return (-1);
	}
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
			addChannel(hub, message, params[i]);
		else
		{
			joinChannel(channel, message, params[i]);
			Debug::Log << "JOIN : The number of op is " << channel->getOperators().size() << std::endl;
		}
	}
	return(_callback);
}