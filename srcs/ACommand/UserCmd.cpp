#include "../../incs/ACommand/ACommand.hpp"
#include "../../incs/ACommand/UserCmd.hpp"
#include "../../incs/Callback.hpp"

#include <iostream>
#include <vector>

UserCmd::UserCmd() : ACommand("USER") {

}

UserCmd::~UserCmd() {
	
}

bool 		UserCmd::checkRegisterState(User * user) {
	if (user->IsRegistered())
	{
		this->_callback.addReply("ERR_ALREADYREGISTERED"); // not created yet
		return false;
	}

	return true;
}

bool 		UserCmd::checkAuthentication(User * user) {
	if (user->isAuth() == false)
	{
		Debug::Log << "USER: wrong password detected for " << user->getNickname() << std::endl;
		_callback.addReply("ERR_PASSWDMISMATCH");
		_callback.setUserDelete(true);
		return false;
	}

	return true;
}

void		UserCmd::registerUser(User * user) {
	std::vector<std::string> paramlist = message.getParamList();

	int paramlen = paramlist.size();
	int realnameIndex = 3;

	if (paramlen == 0 || paramlist[0] == "0")
	{
		user->setName(user->getNickname());
		realnameIndex--;
	} else
		user->setName(paramlist[0]); // truncate USERNAME if length > USERLEN ?

	if (paramlen < realnameIndex)
		user->setRealname(user->getNickname());
	else
		user->setRealname(paramlist[realnameIndex]);

	this->_callback.addReply("RPL_WELCOME");
	this->_callback.addReply("RPL_YOURHOST");
	this->_callback.addReply("RPL_CREATED");
	this->_callback.addReply("RPL_MYINFO");
	this->_callback.addReply("RPL_ISSUPPORT");
	
	this->_callback.addCommand("LUSERS");

	this->_callback.addCommand("MOTD");

	user->Register();
}

Callback	&UserCmd::cmdExecute(Message & message, Hub & hub) {
	(void)hub;

	User *user = message.getSender();

	if (checkRegister(user) == false)
		return this->_callback;

	if (checkAuthentication(user) == false)
		return this->_callback;

	Debug::Log << "USER: " << user->getNickname() << " has been authentified" << std::endl;

	registerUser(user);

	return this->_callback;
}
