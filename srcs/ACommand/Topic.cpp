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
	if (istopic == 0)
	{
		if (channel->get_topic().size() == 0)
		{
			_callback.addReply("RPL_NOTOPIC", Paramlist[0]);
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
		if (Paramlist[1].size() == 0)
		{
			std::string messageparam = channel->get_name() + " :";
			//TO DO a terminer, supprimer le topic
		}
		else
		{
			//TO DO a terminer, changer le topic
		}
	}
	return (_callback);
}
