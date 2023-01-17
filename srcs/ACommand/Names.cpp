#include "../../incs/ACommand/Names.hpp"

Names::Names() : ACommand("NAMES"){

}

Names::~Names() {
	
}

Callback	&Names::cmdExecute(Message & message, Hub & hub)
{
	Debug::Log << "Names : Names has been called" << std::endl;


	if (message.getParamList()[0].size() == 0)
		return (_callback);

	std::vector<std::string> params = Utils::split(message.getParamList()[0], ',');
	for (unsigned int i = 0; i < params.size(); i++)
	{
		if (params[i].size() == 0)
			continue;
		Channel	*channel = hub.getChannelByName(params[i]);
		if (channel == NULL)
		{
			_callback.addReply("RPL_ENDOFNAMES", params[i]);
			continue;
		}
		_callback.addReply("RPL_NAMEREPLY", params[i]);
		_callback.addReply("RPL_ENDOFNAMES", params[i]);
	}
	return (_callback);
}
