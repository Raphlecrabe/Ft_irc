#include "../../incs/AReply/Pong.hpp"


Pong::Pong() : AReply("PONG") {

}

Pong::~Pong() {
	
}

Message Pong::getmsg(Hub &hub, Message &message) 
{
	(void)hub;
	Message	newmessage(":lebestserver.com", "PONG", message.getParamList()[0]);

	newmessage.destinator = message.getSender();
	answer = newmessage;
	return (answer);
}