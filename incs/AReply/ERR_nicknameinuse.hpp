#ifndef ERR_NICKNAMEINUSE_HPP
# define ERR_NICKNAMEINUSE_HPP

# include "AReply.hpp"

class ERR_nicknameinuse : public AReply{
	private:

	public:
		ERR_nicknameinuse();
		~ERR_nicknameinuse();

		Message	getmsg(Hub &hub, Message &message);
};

#endif