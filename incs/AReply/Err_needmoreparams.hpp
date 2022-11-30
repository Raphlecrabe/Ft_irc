#ifndef ERR_NEEDMOREPARAMS_HPP
# define ERR_NEEDMOREPARAMS_HPP

# include "AReply.hpp"

class Err_needmoreparams : public AReply{
	private:

	public:
		Err_needmoreparams();
		~Err_needmoreparams();

		Message	&getmsg(Hub &hub, Message &message);
};

#endif