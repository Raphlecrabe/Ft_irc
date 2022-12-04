#ifndef RPL_ISSUPPORT_HPP
# define RPL_ISSUPPORT_HPP

# include "AReply.hpp"

class RPL_IsSupport : public AReply{
	private:

	public:
		RPL_IsSupport();
		~RPL_IsSupport();

		Message	getmsg(Hub &hub, Message &message);
};

#endif