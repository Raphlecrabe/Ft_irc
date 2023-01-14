#include "../../incs/ACommand/Privmsg.hpp"

Privmsg::Privmsg() : ACommand("PRIVMSG"){

}

Privmsg::~Privmsg() {
	
}

Callback	&Privmsg::cmdExecute(Message & message, Hub & hub)
{
}