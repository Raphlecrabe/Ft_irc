#ifndef ERR_BADCHANMASK_HPP
# define ERR_BADCHANMASK_HPP

# include "AReply.hpp"

class ERR_Badchanmask : public AReply{
	private:

	public:
		ERR_Badchanmask();
		~ERR_Badchanmask();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif
