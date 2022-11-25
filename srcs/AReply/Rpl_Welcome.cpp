#include "../../incs/AReply/Rpl_Welcome.hpp"
#include "../../incs/AReply/AReply.hpp"

Rpl_Welcome::Rpl_Welcome() : AReply("RPL_WELCOME") {

}

Rpl_Welcome::~Rpl_Welcome() {
	
}

Message Rpl_Welcome::getmsg(Hub &hub, Message message) {
	Message	newmessage(":lebestserver.com", "001", "fbelthoi :Welcome to the Internet Relay Network, fbelthoi");
	(void) hub;
	(void) message;

	newmessage.destinator = message.getSender();

	return (newmessage);
}