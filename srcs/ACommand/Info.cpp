#include "../../incs/ACommand/Info.hpp"

Info::Info() : ACommand("INFO"){

}

Info::~Info() {
	
}

Callback	&Info::cmdExecute(Message & message, Hub & hub)
{
	//Debug
	std::string log = "Info : info has been called";
	Debug::Log(log);

	(void)message;
	(void)hub;
	_callback.addReply("RPL_INFO", "");
	_callback.addReply("RPL_ENDOFINFO", "");
	return (_callback);
}
