#ifndef ERR_ERRONEUSNICKNAME_HPP
# define ERR_ERRONEUSNICKNAME_HPP

# include "AReply.hpp"

class Err_erroneusnickname : public AReply{
	private:

	public:
		Err_erroneusnickname();
		~Err_erroneusnickname();

		Message	&getmsg(Hub &hub, Message &message);
};

#endif