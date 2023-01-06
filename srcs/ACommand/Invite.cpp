#include "../../incs/ACommand/Invite.hpp"

Invite::Invite() : ACommand("INVITE"){

}

Invite::~Invite() {
	
}

Callback	&Invite::cmdExecute(Message & message, Hub & hub)
{
	//Debug
	std::string log = "Invite : Invite has been called";
	Debug::Log(log);

	if (message.getParamList().size() < 2)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS", "INVITE");
		return (_callback);
	}
	int	senderIsOnChannel = 0;
	int invitedIsOnChannel = 0;
	std::string nickparam = message.getParamList()[0];
	std::string chanparam = message.getParamList()[1];
	Channel *channel = hub.getChannelByName(chanparam);
	if (channel == NULL)
	{
		_callback.addReply("ERR_NOSUCHCHANNEL", chanparam);
		return (_callback);
	}
	std::vector<User *> users = channel->get_users();
	for (unsigned int i = 0; i < users.size(); i++)
	{
		if (message.getSender()->getNickname() == users[i]->getNickname())
			senderIsOnChannel = 1;
	}
	if (senderIsOnChannel == 0)
	{
		_callback.addReply("ERR_NOTONCHANNEL", chanparam);
		return (_callback);
	}
	//TO DO Coder la partie avec le mode invite only quand on aura fait les modes
	// et les operateurs
	for (unsigned int i = 0; i < users.size(); i++)
	{
		if (nickparam == users[i]->getNickname())
			invitedIsOnChannel = 1;
	}
	if (invitedIsOnChannel == 1)
	{
		std::string errParam = nickparam + " " + chanparam;
		_callback.addReply("ERR_USERONCHANNEL", errParam);
		return (_callback);
	}

	std::string messageparam = nickparam + " " + channel->get_name();
	Message newmessage(message.getSender()->getNickname(), "INVITE", channel->get_name());
	newmessage.addDestinator(hub.get_UserByNickName(nickparam));
	_callback.addMessage(newmessage);


	std::string replyParam = nickparam + " " + chanparam;
	_callback.addReply("RPL_INVITING", replyParam);

	return (_callback);
}
