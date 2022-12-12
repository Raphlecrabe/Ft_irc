#include "../../incs/ACommand/ACommand.hpp"
#include "../../incs/ACommand/UserCmd.hpp"
#include "../../incs/Callback.hpp"

#include <iostream>
#include <vector>

UserCmd::UserCmd() : ACommand("USER") {

}

UserCmd::~UserCmd() {
	
}

Callback	&UserCmd::cmdExecute(Message & message, Hub & hub) {
	std::vector<std::string> paramlist = message.getParamList();
	
	message.getSender()->setName(paramlist[0]);
	message.getSender()->setRealname(paramlist[3]);

	(void)hub;

	this->_callback.addReply("RPL_WELCOME");
	this->_callback.addReply("RPL_YOURHOST");
	this->_callback.addReply("RPL_CREATED");
	this->_callback.addReply("RPL_MYINFO");
	this->_callback.addReply("RPL_ISSUPPORT");
	
	this->_callback.addReply("RPL_LUSERCLIENT");
	this->_callback.addReply("RPL_LUSERME");

	return this->_callback;
}
