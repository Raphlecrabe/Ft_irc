#include "../../incs/ACommand/Cap.hpp"

Cap::Cap() : ACommand("CAP"){

}

Cap::~Cap() {
	
}

Callback	&Cap::cmdExecute(Message & message, Hub & hub)
{
	(void)message;
	(void)hub;
	Debug::Log("Executing command CAP");
	return _callback;
}