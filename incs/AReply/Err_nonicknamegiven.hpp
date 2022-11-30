#ifndef ERR_NONICKNAMEGIVEN_HPP
# define ERR_NONICKNAMEGIVEN_HPP

# include "AReply.hpp"

class Err_nonicknamegiven : public AReply{
	private:

	public:
		Err_nonicknamegiven();
		~Err_nonicknamegiven();

		Message	getmsg(Hub &hub, Message &message);
};

#endif