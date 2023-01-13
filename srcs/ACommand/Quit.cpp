#include "../../incs/ACommand/Quit.hpp"

Quit::Quit() : ACommand("QUIT"){

}

Quit::~Quit() {
	
}

Callback	&Quit::cmdExecute(Message & message, Hub & hub)
{
	//Debug
	std::string log = "OPER : OPER has been called";
	Debug::Log(log);

	(void)message;
	(void)hub;
	return (_callback);
}
