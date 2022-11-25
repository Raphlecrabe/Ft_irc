#ifndef PONG_HPP
# define PONG_HPP

# include "AReply.hpp"

class Pong : public AReply{
	private:

	public:
		Pong();
		~Pong();

		Message	&getmsg(Hub &hub, Message &message);
};

#endif