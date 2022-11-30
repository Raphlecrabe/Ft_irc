#ifndef ERR_NONICKNAMEGIVEN_HPP
# define ERR_NONICKNAMEGIVEN_HPP

# include "AReply.hpp"

class ERR_nonicknamegiven : public AReply{
	private:

	public:
		ERR_nonicknamegiven();
		~ERR_nonicknamegiven();

		Message	getmsg(Hub &hub, Message &message, std::string &param);
};

#endif