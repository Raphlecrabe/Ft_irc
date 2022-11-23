#include "../../incs/AReply/Rpl_Welcome.hpp"
#include "../../incs/AReply/AReply.hpp"

Rpl_Welcome::Rpl_Welcome() : AReply("RPL_WELCOME") {

}

Rpl_Welcome::~Rpl_Welcome() {
	
}

std::string Rpl_Welcome::getmsg() {
	return "fbelthoi :Welcome to the Internet Relay Network fbelthoi!fbelthoi@localhost";
}