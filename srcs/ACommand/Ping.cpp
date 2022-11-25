#include "../../incs/ACommand/Ping.hpp"

Ping::Ping() : ACommand("PING"){

}

Ping::~Ping() {
	
}

Callback	&Ping::cmdExecute(Message & message, Hub & hub)
{
	(void)hub;
	if (message.getParams().empty() == 1)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS");
		return _callback;
	}
	_callback.addReply("PONG");
	return _callback;
}