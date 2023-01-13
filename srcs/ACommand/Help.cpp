#include "../../incs/ACommand/Help.hpp"

Help::Help() : ACommand("HELP"){

}

Help::~Help() {
	
}

Callback	&Help::cmdExecute(Message & message, Hub & hub)
{
	Debug::Log << "HELP : HELP has been called" << std::endl;

	(void)hub;
	_callback.addReply("ERR_HELPNOTFOUND", message.getParamList()[0]);
	return (_callback);
}
