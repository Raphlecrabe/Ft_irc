#include "../../incs/ACommand/Pass.hpp"

Pass::Pass() : ACommand("PASS"){

}

Pass::~Pass() {
	
}

Callback	&Pass::cmdExecute(Message & message, Hub & hub)
{
	std::vector<std::string> param = message.getParamList();

	if (param[0] == hub.getServerPassword())
		message.getSender()->setAuth();

	return _callback;
}
