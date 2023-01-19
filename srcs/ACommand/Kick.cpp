#include "../../incs/ACommand/Kick.hpp"

Kick::Kick() : ACommand("KICK"){

}

Kick::~Kick() {
	
}

Callback	&Kick::cmdExecute(Message & message, Hub & hub)
{
	Debug::Log << "Kick : Kick has been called" << std::endl;


	std::vector<std::string> messageparams = Utils::split(message.getParams(), ' ');
	int	comment = 0;
	if (messageparams.size() < 2)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS", "KICK");
		return (_callback);
	}
	if (messageparams.size() >= 3)
	{
		comment = 1;
	}
	std::vector<std::string> userparam = Utils::split(messageparams[1], ',');
	Channel *channel = hub.getChannelByName(messageparams[0]);
	if (channel == NULL)
	{
		_callback.addReply("ERR_NOSUCHCHANNEL", messageparams[0]);
		return (_callback);
	}
	if (hub.isIrcOperator(message.getSender()) == 0 && channel->isChannelOperator(message.getSender()) == 0)
	{
		_callback.addReply("ERR_CHANOPRIVSNEEDED", messageparams[0]);
		return (_callback);
	}
	std::string param;
	for (size_t i = 0; i < userparam.size(); i++)
	{
		param.clear();
		User *user = hub.get_UserByNickName(userparam[i]);
		if (user == NULL || channel->UserIsInChannel(user) == 0)
		{
			std::string replyparam = userparam[i] + " " + channel->get_name();
			_callback.addReply("ERR_USERNOTINCHANNEL", replyparam);
			continue;
		}
		else
		{
			param = channel->get_name() + " " + user->getNickname();
			if (comment == 1)
				param += messageparams[3];
			Message	kickmessage(message.getSender()->getNickname(), "KICK", param);
			channel->addDestinatorsExceptOneInMessage(message.getSender(), kickmessage);
			kickmessage.addDestinator(message.getSender());
			_callback.addMessage(kickmessage);
			user->RemoveChannel(channel);
			if (channel->RemoveUser(*user) == -1)
				hub.removeChannelByName(channel->get_name());
		}
	}
	return (_callback);
}
