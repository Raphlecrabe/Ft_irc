#include "../../incs/ACommand/Join.hpp"

Join::Join() : ACommand("JOIN"){

}

Join::~Join() {
	
}

Callback	&Join::cmdExecute(Message & message, Hub & hub)
{
	if (message.getParamList().size() == 0)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS", "");
		return (_callback);
	}

	std::vector<std::string> params = message.getParamList();
	for (unsigned int i = 0; i < message.getParamList().size(); i++)
	{
		Channel	*channel = hub.getChannelByName(params[i]);
		if (channel == NULL)
		{
			try
			{
				hub.CreateChannel(params[i], *message.getSender());
			}
			catch(const std::exception &e)
			{
				_callback.addReply(e.what(), "");
				continue;
			}
			_callback.addReply("RPL_TOPIC", params[i]);
			_callback.addReply("RPL_NAMEREPLY", params[i]);
			_callback.addReply("RPL_ENDOFNAMES", params[i]);
			continue;
		}
		if (channel->AddUser(*(message.getSender())) == -1)
		{
			_callback.addReply("ERR_CHANNELISFULL", params[i]);
			continue;
		}
		channel->AddFd(message.getSender()->getFd());
		_callback.addReply("RPL_TOPIC", params[i]);
		_callback.addReply("RPL_NAMEREPLY", params[i]);
		_callback.addReply("RPL_ENDOFNAMES", params[i]);
		// TO DO : Faire la partie ou on envoit les messages à tous les utilisateurs du channel
		// pour leur signaler que machin vient de rejoindre
		// TO DO : Faire un système de fonctions qui génère les messages à tout le serveur
	}
	return(_callback);
}