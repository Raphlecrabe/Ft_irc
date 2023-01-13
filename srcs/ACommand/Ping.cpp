#include "../../incs/ACommand/Ping.hpp"

Ping::Ping() : ACommand("PING"){

}

Ping::~Ping() {
	
}

Callback	&Ping::cmdExecute(Message & message, Hub & hub)
{
	std::string params = hub.getServerName() + " " + message.getParams();

	Message pong(hub.getServerName(), "PONG", params);

	pong.addDestinator(message.getSender());

	_callback.addMessage(pong);

	return _callback;
}