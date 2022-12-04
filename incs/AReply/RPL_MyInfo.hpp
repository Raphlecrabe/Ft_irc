#ifndef RPL_MYINFO_HPP
# define RPL_MYINFO_HPP

# include "AReply.hpp"

class RPL_MyInfo : public AReply{
	private:

	public:
		RPL_MyInfo();
		~RPL_MyInfo();

		Message	getmsg(Hub &hub, Message &message);
};

#endif