#ifndef AREPLY_HPP
# define AREPLY_HPP

# include <iostream>
# include "../Callback.hpp"
# include "../Hub.hpp"
# include "../Debug.hpp"

class AReply {
	private:
		std::string _name;

	public:
		AReply(std::string name) : _name(name) {}
		virtual ~AReply() {}

		std::string &getName() { return _name; }
		virtual	Message getmsg(Hub &hub, Message &message) = 0;
};

#endif