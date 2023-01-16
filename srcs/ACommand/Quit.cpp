#include "../../incs/ACommand/Quit.hpp"

Quit::Quit() : ACommand("QUIT"){

}

Quit::~Quit() {
	
}

Callback	&Quit::cmdExecute(Message & message, Hub & hub)
{
	this->_callback.addReply("ERROR", message.getParamList()[0]);

	_callback.setUserDelete(true);

	hub.program_to_close(message.getSender()->getFd());

	std::string reason = "Quit: " + message.getParams();

	Message clientsQuitMessage = message.getSender()->getQuitMessage(reason);

	this->_callback.addMessage(clientsQuitMessage);

	return this->_callback;
}