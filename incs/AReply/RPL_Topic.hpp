#ifndef RPL_TOPIC_HPP
# define RPL_TOPIC_HPP

# include "AReply.hpp"

class RPL_Topic : public AReply{
	private:

	public:
		RPL_Topic();
		~RPL_Topic();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif
