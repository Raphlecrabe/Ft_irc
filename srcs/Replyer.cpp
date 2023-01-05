#include "../incs/Replyer.hpp"
#include "../incs/Callback.hpp"

Replyer::Replyer(Sender &sender, Hub &hub) : _sender(sender), _hub(hub) {

}

Replyer::~Replyer() 
{
}

void	Replyer::TreatReplys(Callback &callback, Message &message)
{
	std::vector< s_pair > Replys = callback.getReplys();
	std::vector< s_pair >::iterator it;

	if (Replys.size() == 0)
		return;
	for(it = Replys.begin(); it != Replys.end(); it++)
	{
		if (Replyone(it->first, message, it->second) == -1)
		{
			//Erreur la reply est pas dans notre base de donnée
			continue;
		}
	}
	callback.resetReplys();
}

int	Replyer::Replyone(std::string &name, Message &message, std::string param)
{
	AReply	*reply = this->_ReplyCreator.getReplyByName(name);
	if (reply == NULL)
	{
		//Debug
		std::string log = "Replyer :Reply " + name + " :Not found";
		Debug::Log(log);
		//Erreur la reply n'est pas dans notre base de donnée
		return (-1);
	}

	Debug::Log(std::string("Replyer :Replying : " + reply->getName()));

	try {
		this->_sender.sendto(reply->getmsg(_hub, message, param));
	} catch (std::exception &e) {
		Debug::Log(e.what());
		std::cout << e.what() << std::endl;
	}

	return (0);
}
