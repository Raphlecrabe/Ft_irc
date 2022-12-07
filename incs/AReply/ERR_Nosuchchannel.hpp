#ifndef ERR_NOSUCHCHANNEL_HPP
# define ERR_NOSUCHCHANNEL_HPP

# include "AReply.hpp"

class ERR_Nosuchchannel : public AReply{
	private:

	public:
		ERR_Nosuchchannel();
		~ERR_Nosuchchannel();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif
