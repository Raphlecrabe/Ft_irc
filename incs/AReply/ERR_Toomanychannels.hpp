#ifndef ERR_TOOMANYCHANNELS_HPP
# define ERR_TOOMANYCHANNELS_HPP

# include "AReply.hpp"

class ERR_Toomanychannels : public AReply{
	private:

	public:
		ERR_Toomanychannels();
		~ERR_Toomanychannels();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif
