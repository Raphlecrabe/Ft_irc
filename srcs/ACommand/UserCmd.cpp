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

	if (message.getSender()->IsRegistered())
	{
		this->_callback.addReply("ERR_ALREADYREGISTERED"); // not created yet
		return this->_callback;
	}

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

	int maxindex = 3;

	if (paramlist.size() == 0 || paramlist[0] == "0")
	{
		message.getSender()->setName(message.getSender()->getNickname());
		maxindex--;
	} else
		message.getSender()->setName(paramlist[0]); // truncate USERNAME if length > USERLEN ?

	if ((int)paramlist.size() < (maxindex + 1))
		message.getSender()->setRealname(message.getSender()->getNickname());
	else
		message.getSender()->setRealname(paramlist[maxindex]);


	(void)hub;

	this->_callback.addReply("RPL_WELCOME");
	this->_callback.addReply("RPL_YOURHOST");
	this->_callback.addReply("RPL_CREATED");
	this->_callback.addReply("RPL_MYINFO");
	this->_callback.addReply("RPL_ISSUPPORT");
	
	this->_callback.addCommand("LUSERS");

	this->_callback.addCommand("MOTD");

	message.getSender()->Register();

	return this->_callback;
}
