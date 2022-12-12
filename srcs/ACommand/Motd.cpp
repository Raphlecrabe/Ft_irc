#include "../../incs/ACommand/Motd.hpp"

Motd::Motd() : ACommand("MOTD"){

}

Motd::~Motd() {
	
}

Callback	&Motd::cmdExecute(Message & message, Hub & hub)
{
	std::vector<std::string> paramlist = message.getParamList();

	if (paramlist.size() > 0 && (paramlist[0] != hub.getServerName()))
	{
		_callback.addReply("ERR_NOSUCHSERVER", paramlist[0]);
		return _callback;
	}

	if (hub.getMessageOfTheDay() == NULL)
	{
		_callback.addReply("ERR_NOMOTD");
		return _callback;
	}

	_callback.addReply("RPL_MOTDSTART");
	_callback.addReply("RPL_MOTD");
	_callback.addReply("RPL_ENDOFMOTD");

	return _callback;
}
