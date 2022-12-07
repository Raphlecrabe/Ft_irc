#ifndef ERR_NOTONCHANNEL_HPP
# define ERR_NOTONCHANNEL_HPP

# include "AReply.hpp"

class ERR_notonchannel : public AReply{
	private:

	public:
		ERR_notonchannel();
		~ERR_notonchannel();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif
