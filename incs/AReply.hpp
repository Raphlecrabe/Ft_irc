#ifndef AREPLY_HPP
# define AREPLY_HPP

#include <iostream>

class AReply {
	private:
		std::string _name;

	public:
		AReply(std::string name);
		virtual ~AReply();

		std::string getName();
		virtual std::string getmsg() = 0;
};

#endif