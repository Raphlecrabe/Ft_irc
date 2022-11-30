#ifndef RPL_WELCOME_HPP
# define RPL_WELCOME_HPP

# include "AReply.hpp"

# include <iostream>

class Rpl_Welcome : public AReply {
	private:

	public:
		Rpl_Welcome();
		~Rpl_Welcome();

		Message getmsg(Hub &hub, Message &messsage);
};

#endif