#include "../incs/Replyer.hpp"

Replyer::Replyer() 
{
}

Replyer::~Replyer() 
{
}

void	Replyer::TreatReplys(std::vector<string> Replys, Hub hub, Message message)
{
	for(std::vector<string>::iterator it = Replys.begin(),
		it != Replys.end(), it++)
	{
		Replyone(*it, hub, message);
	}
}

void	Replyer::Replyone(string name, Hub hub, Message message)
{
	Message	reply;
	int	size = this->_Replies.size();

	reply = this->_Replies[name].getmsg(hub, message);
	if (size != this->_Replies.size())
	{
		//Erreur la reply n'est pas dans notre base de donnée
		//Va falloir supprimer la ligne de reply en trop 
		//et envoyer un message d'erreur ?
	}
	this->Sender.SendTo(reply);
}
