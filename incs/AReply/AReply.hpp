#ifndef AREPLY_HPP
# define AREPLY_HPP

# include <iostream>
# include "../CallBack.hpp"

class AReply {
	private:
		std::string _name;

	public:
		AReply(std::string name);
		virtual ~AReply();

		std::string getName();
		virtual	CallBack	*getmsg(Hub hub) = 0;
};

#endif