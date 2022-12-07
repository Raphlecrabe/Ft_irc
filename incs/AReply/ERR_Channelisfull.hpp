#ifndef ERR_CHANNELISFULL_HPP
# define ERR_CHANNELISFULL_HPP

# include "AReply.hpp"

class ERR_Channelisfull : public AReply{
	private:

	public:
		ERR_Channelisfull();
		~ERR_Channelisfull();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif
