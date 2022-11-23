#include "../incs/Replyer.hpp"

Replyer::Replyer() 
{
}

Replyer::~Replyer() 
{
}

// void	Replyer::TreatReplys(std::vector<std::string> Replys, Hub hub, Message message)
// {
// 	std::vector<std::string>::iterator it;

// 	for(it = Replys.begin(); it != Replys.end(); it++)
// 	{
// 		// Replyone(*it, hub, message);
// 	}
// }

// void	Replyer::Replyone(std::string name, Hub & hub, Message message)
// {
// 	// Message	reply;

// 	// int	size = this->Replys.size();

// 	// reply = this->Replys[name].getmsg(hub, message);
// 	// if (size != this->Replys.size())
// 	// {
// 	// 	//Erreur la reply n'est pas dans notre base de donnée
// 	// 	//Va falloir supprimer la ligne de reply en trop 
// 	// 	//et envoyer un message d'erreur ?
// 	// }
// 	// this->Sender.SendTo(reply);
// }
