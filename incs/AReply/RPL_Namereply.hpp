#ifndef RPL_NAMEREPLY_HPP
# define RPL_NAMEREPLY_HPP

# include "AReply.hpp"

class RPL_Namereply : public AReply{
	private:

	public:
		RPL_Namereply();
		~RPL_Namereply();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif
