#ifndef NAME_HPP
# define NAME_HPP

# include "AReply.hpp"

class Name : public AReply{
	private:

	public:
		Name();
		~Name();

		Message	getmsg(Hub &hub, Message message);
};

#endif