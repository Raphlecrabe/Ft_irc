#include "../../incs/ACommand/Part.hpp"

Part::Part() : ACommand("PART"){

}

Part::~Part() {
	
}

Callback	&Part::cmdExecute(Message & message, Hub & hub)
{
	Debug::Log("Executing command PART");
	std::vector<std::string>	Paramlist = Utils::split(message.getParamList()[0], ',');
	std::vector<std::string>::iterator	it;

	if (Paramlist.size() == 0)
	{
		return (_callback);
	}

	int	reason = 0;
	if (message.getParamList().size() >= 2)
		reason = 1;

	for (it = Paramlist.begin(); it != Paramlist.end(); it++)
	{
		Channel *channel = hub.getChannelByName((*it));
		if (channel == NULL)
		{
			_callback.addReply("ERR_NOSUCHCHANNEL", *it);
		}
		if (channel->UserIsInChannel(message.getSender()) == 0)
		{
			_callback.addReply("ERR_NOTONCHANNEL", *it);
		}
		channel->RemoveUser(*message.getSender());
		std::string	messageparam = channel->get_name();
		if (reason == 1)
			messageparam += " " + message.getParamList()[1];
		Message	newmessage(message.getSender()->getName(), "PART", messageparam);
		newmessage.addDestinator(message.getSender());
		channel->addDestinatorsExceptOneInMessage(message.getSender(), newmessage);
		_callback.addMessage(newmessage);
	}
	return (_callback);
}
