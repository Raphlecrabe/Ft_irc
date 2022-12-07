#ifndef RPL_TEST_HPP
# define RPL_TEST_HPP

# include "AReply.hpp"

class RPL_Test : public AReply{
	private:

	public:
		RPL_Test() : AReply("RPL_TEST") {};
		~RPL_Test() {}

		Message	getmsg(Hub &hub, Message &message) {
			Message newmessage("source", "command", "params");

			return newmessage;
		}
};

#endif
