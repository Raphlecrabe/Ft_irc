#ifndef ERR_NICKNAMEINUSE_HPP
# define ERR_NICKNAMEINUSE_HPP

# include "AReply.hpp"

class Err_nicknameinuse : public AReply{
	private:

	public:
		Err_nicknameinuse();
		~Err_nicknameinuse();

		Message	&getmsg(Hub &hub, Message &message);
};

#endif