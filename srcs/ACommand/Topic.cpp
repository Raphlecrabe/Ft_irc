#include "../../incs/ACommand/Topic.hpp"

Topic::Topic() : ACommand("TOPIC"){

}

Topic::~Topic() {
	
}

Callback	&Topic::cmdExecute(Message & message, Hub & hub)
{
	int	istopic = 0;
	std::vector<std::string>	Paramlist = message.getParamList();
	if (Paramlist.size() == 0)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS", "");
		return (_callback);
	}
	if (Paramlist.size() >= 2)
		istopic = 1;
	Channel *channel =hub.getChannelByName(Paramlist[0]);
	if (channel == NULL)
	{
		_callback.addReply("ERR_NOSUCHCHANNEL", Paramlist[0]);
		return(_callback);
	}
	if (channel->UserIsInChannel(message.getSender()) == 0)
	{
		_callback.addReply("ERR_NOTONCHANNEL", channel->get_name());
		return (_callback);
	}	
	if (istopic == 0)
	{
		if (channel->get_topic().size() == 0)
		{
			_callback.addReply("RPL_TOPIC", Paramlist[0]);
			return (_callback);
		}
		else
		{
			_callback.addReply("RPL_TOPIC", Paramlist[0]);
			return(_callback);
		}
	}
	if (istopic == 1)
	{
		channel->ChangeTopic(Paramlist[1]);
		std::string messageparam = channel->get_name() + " :" + Paramlist[1];
		Message	newmessage(message.getSender()->getName(), "TOPIC", messageparam);
		newmessage.addDestinator(message.getSender());
		channel->addDestinatorsExceptOneInMessage(message.getSender(), newmessage);
		_callback.addMessage(newmessage);
	}
	return (_callback);
}
