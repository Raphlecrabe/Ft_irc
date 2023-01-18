#include "../../incs/ACommand/Pass.hpp"

Pass::Pass() : ACommand("PASS"){

}

Pass::~Pass() {
	
}

Callback	&Pass::cmdExecute(Message & message, Hub & hub)
{
	std::vector<std::string> param = message.getParamList();

	if (param.size() == 0)
		this->_callback.addReply("ERR_NEEDMOREPARAMS");
	else if (param[0] == hub.getServerPassword())
		message.getSender()->setAuth(true);
	else
		message.getSender()->setAuth(false);

	return this->_callback;
}
