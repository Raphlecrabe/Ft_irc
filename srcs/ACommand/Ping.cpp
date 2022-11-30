#include "../../incs/ACommand/Ping.hpp"

Ping::Ping() : ACommand("PING"){

}

Ping::~Ping() {
	
}

Callback	&Ping::cmdExecute(Message & message, Hub & hub)
{
	std::string params = hub.getServerName() + " " + message.getParams();

	Message pong("", "PONG", params);

	pong.destinator = message.getSender();

	_callback.addMessage(pong);

	return _callback;
}