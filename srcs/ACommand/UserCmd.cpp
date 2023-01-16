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

	if (message.getSender()->isAuth() == false)
	{
		Debug::Log << "USER: wrong password detected for " << message.getSender()->getNickname() << std::endl;
		_callback.addReply("ERR_PASSWDMISMATCH");
		_callback.addReply("ERROR", "incorrect password");
		_callback.setUserDelete(true);
		//hub.program_to_close(message.getSender()->getFd());
		return this->_callback;
	}

	Debug::Log << "USER: " << message.getSender()->getNickname() << " has been authentified" << std::endl;

	std::vector<std::string> paramlist = message.getParamList();
	
	message.getSender()->setName(paramlist[0]);
	message.getSender()->setRealname(paramlist[3]);

	(void)hub;

	this->_callback.addReply("RPL_WELCOME");
	this->_callback.addReply("RPL_YOURHOST");
	this->_callback.addReply("RPL_CREATED");
	this->_callback.addReply("RPL_MYINFO");
	this->_callback.addReply("RPL_ISSUPPORT");
	
	this->_callback.addCommand("LUSERS");

	this->_callback.addCommand("MOTD");

	return this->_callback;
}
