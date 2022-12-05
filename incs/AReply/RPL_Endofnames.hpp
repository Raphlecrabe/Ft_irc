#ifndef RPL_ENDOFNAMES_HPP
# define RPL_ENDOFNAMES_HPP

# include "AReply.hpp"

class RPL_Endofnames : public AReply{
	private:

	public:
		RPL_Endofnames();
		~RPL_Endofnames();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif
