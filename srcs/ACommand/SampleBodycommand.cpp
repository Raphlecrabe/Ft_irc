#include "../../incs/ACommand/Name.hpp"

Name::Name() : ACommand("NAME"){

}

Name::~Name() {
	
}

Callback	&Name::cmdExecute(Message & message, Hub & hub)
{
}