#include "../../incs/AReply/Rpl_Welcome.hpp"
#include "../../incs/AReply/AReply.hpp"

Rpl_Welcome::Rpl_Welcome() : AReply("RPL_WELCOME") {

}

Rpl_Welcome::~Rpl_Welcome() {
	
}

Message Rpl_Welcome::getmsg(Hub &hub, Message message) {
	Message	newmessage("src", "cmd", "params");
	(void) hub;
	(void) message;
	return (newmessage);
}