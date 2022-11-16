#include "../incs/Replier.hpp"
#include "../incs/AReply.hpp"
#include <map>
#include <vector>

Replier::Replier(std::vector<AReply *> replies) {

	int len = replies.size();

	for (int i = 0; i < len; i++)
	{
		_dict.insert( std::pair<std::string, AReply *>(replies[i]->getName(), replies[i]) );
	}

}

Replier::~Replier() {
	
}

std::string Replier::getReplyByName(std::string name) {
	AReply * reply = _dict[name];

	if (reply == NULL)
		return NULL;
	
	return reply->getmsg();
}