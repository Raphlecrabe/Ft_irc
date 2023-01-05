#include "../../incs/ACommand/Lusers.hpp"

Lusers::Lusers() : ACommand("LUSERS"){

}

Lusers::~Lusers() {
	
}

Callback	&Lusers::cmdExecute(Message & message, Hub & hub)
{
	(void)message;
	(void)hub;

	_callback.addReply("RPL_LUSERCLIENT");
	_callback.addReply("RPL_LUSERME");

	return _callback;
}
