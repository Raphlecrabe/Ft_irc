#include "../../incs/ACommand/Kill.hpp"

Kill::Kill() : ACommand("KILL"){

}

Kill::~Kill() {
	
}

Callback	&Kill::cmdExecute(Message & message, Hub & hub)
{
	if (message.getParamList().size() < 2)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS", "KILL");
		return (_callback);
	}
	if (hub.get_UserByNickName(message.getParamList()[0]) == NULL)
	{
		_callback.addReply("ERR_NOSUCHNICK", message.getParamList()[0]);
		return (_callback);
	}
	if (hub.isIrcOperator(message.getSender()) == 0)
	{
		_callback.addReply("ERR_NOPRIVILEGES");
		return (_callback);
	}

	//KILL Message
	std::string messageparam = message.getParamList()[0] + " " + message.getParamList()[1];
	Message newmessage(message.getSender()->getNickname(), "KILL", messageparam);
	newmessage.addDestinator(hub.get_UserByNickName(message.getParamList()[0]));
	_callback.addMessage(newmessage);

	//QUIT Message
	User *user = hub.get_UserByNickName(message.getParamList()[0]);
	std::string messageparam2 = "Killed (" + message.getSender()->getNickname() + " (" + message.getParamList()[1] + "))";
	Message newmessage2 = user->getQuitMessage(messageparam2);
	_callback.addMessage(newmessage2);

	//ERROR Message
	std::string replyparam = "Closing Link: " + hub.getServerName();
	replyparam += " (" + message.getParamList()[0] + " (" + message.getSender()->getNickname();
	replyparam += " (" + message.getParamList()[1] + ")))";
	Message newmessageerror(hub.getServerName(), "ERROR", replyparam);
	newmessageerror.addDestinator(user);
	_callback.addMessage(newmessageerror);

	//Closing Connection
	hub.program_to_close(user->getFd());
	_callback.setUserDelete(user);

	return (_callback);
}
