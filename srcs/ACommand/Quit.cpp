#include "../../incs/ACommand/Quit.hpp"

Quit::Quit() : ACommand("QUIT"){

}

Quit::~Quit() {
	
}

Callback	&Quit::cmdExecute(Message & message, Hub & hub)
{
	std::vector<std::string> paramList = message.getParamList();
	std::string param = "";
	if (paramList.size() > 0)
		param = paramList[0];

	this->_callback.addReply("ERROR", param);

	_callback.setUserDelete(message.getSender());

	hub.program_to_close(message.getSender()->getFd());

	std::string reason = ":Quit: " + param;

	Message clientsQuitMessage = message.getSender()->getQuitMessage(reason);

	this->_callback.addMessage(clientsQuitMessage);

	return this->_callback;
}