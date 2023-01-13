#include "../../incs/ACommand/Info.hpp"

Info::Info() : ACommand("INFO"){

}

Info::~Info() {
	
}

Callback	&Info::cmdExecute(Message & message, Hub & hub)
{
	Debug::Log << "Info : info has been called" << std::endl;

	(void)message;
	(void)hub;
	_callback.addReply("RPL_INFO", "");
	_callback.addReply("RPL_ENDOFINFO", "");
	return (_callback);
}
