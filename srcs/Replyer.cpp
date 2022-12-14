#include "../incs/Replyer.hpp"

Replyer::Replyer(Sender &sender, Hub &hub) : _sender(sender), _hub(hub) {

}

Replyer::~Replyer() 
{
}

void	Replyer::TreatReplys(Callback &callback, Message &message)
{
	std::vector<std::string> Replys = callback.getReplys();
	std::vector<std::string>::iterator it;
	std::vector<std::string>::const_iterator it2 = callback.getReplyParams().begin();

	if (Replys.size() == 0)
		return;
	for(it = Replys.begin(); it != Replys.end(); it++)
	{
		it2 ++;
		if (Replyone(*it, message, *it2) == -1)
		{
			//Erreur la reply est pas dans notre base de donnée
			continue;
		}
	}
	callback.resetReplys();
	callback.resetReplyparams();
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
