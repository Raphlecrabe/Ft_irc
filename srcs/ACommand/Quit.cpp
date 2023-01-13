#include "../../incs/ACommand/Quit.hpp"

Quit::Quit() : ACommand("QUIT"){

}

Quit::~Quit() {
	
}

Callback	&Quit::cmdExecute(Message & message, Hub & hub)
{
	Debug::Log << "OPER : OPER has been called" << std::endl;

	(void)message;
	(void)hub;
	return (_callback);
}
