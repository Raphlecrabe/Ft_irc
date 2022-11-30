#ifndef ERR_NEEDMOREPARAMS_HPP
# define ERR_NEEDMOREPARAMS_HPP

# include "AReply.hpp"

class ERR_needmoreparams : public AReply{
	private:

	public:
		ERR_needmoreparams();
		~ERR_needmoreparams();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif