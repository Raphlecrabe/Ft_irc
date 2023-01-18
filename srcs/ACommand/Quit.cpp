#include "../../incs/ACommand/Quit.hpp"

Quit::Quit() : ACommand("QUIT"){

}

Quit::~Quit() {
	
}

Callback	&Quit::cmdExecute(Message & message, Hub & hub)
{
	this->_callback.addReply("ERROR", message.getParamList()[0]);

	_callback.setUserDelete(message.getSender());

	hub.program_to_close(message.getSender()->getFd());

	std::string reason = ":Quit: ";
	if (message.getParamList().size() > 0)
		reason += message.getParamList()[0];

	Message clientsQuitMessage = message.getSender()->getQuitMessage(reason);

	this->_callback.addMessage(clientsQuitMessage);

	return this->_callback;
}