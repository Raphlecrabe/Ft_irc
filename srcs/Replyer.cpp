#include "../incs/Replyer.hpp"

Replyer::Replyer(Hub &hub) : _hub(hub) 
{
}

Replyer::~Replyer() 
{
}

void	Replyer::TreatReplys(Callback &callback, Message &message)
{
	std::vector<std::string> Replys = callback.getReplys();
	std::vector<std::string>::iterator it;

	if (Replys.size() == 0)
		return;
	for(it = Replys.begin(); it != Replys.end(); it++)
	{
		if (Replyone(*it, message) == -1)
		{
			//Erreur la reply est pas dans notre base de donnée
			continue;
		}
	}
	callback.resetReplys();
}

int	Replyer::Replyone(std::string &name, Message &message)
{
	AReply	*reply = this->_ReplyCreator.getReplyByName(name);
	if (reply == NULL)
	{
		//Erreur la reply n'est pas dans notre base de donnée
		return (-1);
	}
	this->_Sender.sendto(reply->getmsg(_hub, message));
	return (0);
}
