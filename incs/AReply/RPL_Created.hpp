#ifndef RPL_CREATED_HPP
# define RPL_CREATED_HPP

# include "AReply.hpp"

class RPL_Created : public AReply{
	private:

	public:
		RPL_Created();
		~RPL_Created();

		Message	getmsg(Hub &hub, Message &message);
};

#endif