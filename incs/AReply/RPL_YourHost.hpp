#ifndef RPL_YOURHOST_HPP
# define RPL_YOURHOST_HPP

# include "AReply.hpp"

class RPL_YourHost : public AReply{
	private:

	public:
		RPL_YourHost();
		~RPL_YourHost();

		Message	getmsg(Hub &hub, Message message);
};

#endif
