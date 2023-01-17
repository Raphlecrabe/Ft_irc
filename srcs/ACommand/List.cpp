#include "../../incs/ACommand/List.hpp"

List::List() : ACommand("LIST"){

}

List::~List() {
	
}

Callback	&List::cmdExecute(Message & message, Hub & hub)
{
	Debug::Log << "List : List has been called" << std::endl;


	_callback.addReply("RPL_LISTSTART", "");
	if (message.getParamList().size() == 0)
	{
		std::vector<Channel *>::const_iterator it;
		for (it = hub.getChannelList().begin(); it != hub.getChannelList().end(); it++)
		{
			_callback.addReply("RPL_LIST", (*it)->get_name());
		}
		_callback.addReply("RPL_LISTEND", "");
		Debug::Log << "List : All channels have been listed" << std::endl;
		return (_callback);
	}
	else
	{
		std::vector<std::string> params = Utils::split(message.getParamList()[0], ',');
		for (unsigned int i = 0; i < params.size(); i++)
		{
			Debug::Log << params[i] << ", ";
		}
		Debug::Log << std::endl;
		for (unsigned int i = 0; i < params.size(); i++)
		{
			if (params[i].size() == 0)
			continue;
			Channel	*channel = hub.getChannelByName(params[i]);
			if (channel == NULL)
			{
				continue;
			}
			_callback.addReply("RPL_LIST", params[i]);
		}
		_callback.addReply("RPL_LISTEND", "");
		Debug::Log << "List : Some channels have been listed" << std::endl;
		return (_callback);
	}
}
