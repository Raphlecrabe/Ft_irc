#include "../../incs/ACommand/Help.hpp"

Help::Help() : ACommand("HELP"){

}

Help::~Help() {
	
}

Callback	&Help::cmdExecute(Message & message, Hub & hub)
{
	//Debug
	std::string log = "HELP : HELP has been called";
	Debug::Log(log);

	(void)hub;
	_callback.addReply("ERR_HELPNOTFOUND", message.getParamList()[0]);
	return (_callback);
}
