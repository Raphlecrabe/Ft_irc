#include "../../incs/ACommand/Ping.hpp"

Ping::Ping() : ACommand("PING"){

}

Ping::~Ping() {
	
}

Callback	&Ping::cmdExecute(Message & message, Hub & hub)
{
	if (message.getParamList().size() == 0)
	{
		_callback.addReply("ERR_NEEDMOREPARAMS");
		return _callback;
	}

	std::string params = hub.getServerName() + " " + message.getParams();

	Message pong(hub.getServerName(), "PONG", params);

	pong.addDestinator(message.getSender());

	_callback.addMessage(pong);

	return _callback;
}