#ifndef RPL_WELCOME_HPP
# define RPL_WELCOME_HPP

# include "AReply.hpp"

# include <iostream>

class RPL_Welcome : public AReply {
	private:

	public:
		RPL_Welcome();
		~RPL_Welcome();

		Message getmsg(Hub &hub, Message &messsage, std::string &param);
};

#endif