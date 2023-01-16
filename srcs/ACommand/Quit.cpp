#include "../../incs/ACommand/Quit.hpp"

Quit::Quit() : ACommand("QUIT"){

}

Quit::~Quit() {
	
}

Callback	&Quit::cmdExecute(Message & message, Hub & hub)
{
	(void)hub;

	this->_callback.addReply("ERROR", message.getParams());

	hub.close_connection(message.getSender()->getFd());

	std::string reason = "Quit: " + message.getParams();

	Message clientsQuitMessage = message.getSender()->getQuitMessage(reason);

	this->_callback.addMessage(clientsQuitMessage);

	return this->_callback;
}