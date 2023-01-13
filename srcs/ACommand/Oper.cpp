#include "../../incs/ACommand/Oper.hpp"

Oper::Oper() : ACommand("OPER"){

}

Oper::~Oper() {
	
}

Callback	&Oper::cmdExecute(Message & message, Hub & hub)
{
	Debug::Log << "OPER : OPER has been called" << std::endl;

	std::vector<std::string> messageparams = Utils::split(message.getParams(), ' ');
	if (messageparams.size() < 2)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS", "OPER");
		return (_callback);
	}
	if (hub.isIrcOperator(message.getSender()) == 1)
	{
		_callback.addReply("RPL_YOUREOPER", "");
		return (_callback);
	}
	if (hub.isInConfig(messageparams[0], messageparams[1]) == 0)
	{
		_callback.addReply("ERR_PASSWDMISMATCH", "");
		return (_callback);
	}
	_callback.addReply("RPL_YOUREOPER", "");
	hub.addIrcOperator(message.getSender());

	//TO DO Changer le param en fonction de ce qui est necessaire pour le message MODE
	std::string param;
	Message	newmessage(message.getSender()->getNickname(), "MODE", param);
	newmessage.addDestinator(message.getSender());
	_callback.addMessage(newmessage);

	return (_callback);
}
