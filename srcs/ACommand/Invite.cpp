#include "../../incs/ACommand/Invite.hpp"

Invite::Invite() : ACommand("INVITE"){

}

Invite::~Invite() {
	
}

int	Invite::userTest(Message message, std::string chanparam, std::string nickparam, Channel channel)
{

	int	senderIsOnChannel = 0;
	int invitedIsOnChannel = 0;
	
	// On verifie que le user source est dans le channel
	std::vector<User *> users = channel->get_users();
	for (unsigned int i = 0; i < users.size(); i++)
	{
		if (message.getSender()->getNickname() == users[i]->getNickname())
			senderIsOnChannel = 1;
	}


	// Le user source n'est pas sur le channel
	if (senderIsOnChannel == 0)
	{
		_callback.addReply("ERR_NOTONCHANNEL", chanparam);
		return (_callback);
	}

	// On verifie que le user cible n'est pas deja sur le channel
	for (unsigned int i = 0; i < users.size(); i++)
	{
		if (nickparam == users[i]->getNickname())
			invitedIsOnChannel = 1;
	}

	// Le user cible est deja sur le channel
	if (invitedIsOnChannel == 1)
	{
		std::string errParam = nickparam + " " + chanparam;
		_callback.addReply("ERR_USERONCHANNEL", errParam);
		return (_callback);
	}
}

Callback	&Invite::cmdExecute(Message & message, Hub & hub)
{
	//Debug
	std::string log = "Invite : Invite has been called";
	Debug::Log(log);


	// Pas assez de paramètre pour pouvoir inviter un User
	if (message.getParamList().size() < 2)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS", "INVITE");
		return (_callback);
	}


	// Recuperation des parametres pour faire plus propre
	std::string nickparam = message.getParamList()[0];
	std::string chanparam = message.getParamList()[1];

	Channel *channel = hub.getChannelByName(chanparam);

	// Le channel n'existe pas
	if (channel == NULL)
	{
		_callback.addReply("ERR_NOSUCHCHANNEL", chanparam);
		return (_callback);
	}

	// Tests sur les users, voir fonction userTest
	if (userTest(message, chanparam, nickparam, channel) == -1)
		return (_callback);

	// Generation du message d'invite pour le user cible
	std::string messageparam = nickparam + " " + channel->get_name();
	Message newmessage(message.getSender()->getNickname(), "INVITE", messageparam);
	newmessage.addDestinator(hub.get_UserByNickName(nickparam));
	_callback.addMessage(newmessage);


	// Generation de la reply pour le user source
	std::string replyParam = nickparam + " " + chanparam;
	_callback.addReply("RPL_INVITING", replyParam);

	return (_callback);
}
