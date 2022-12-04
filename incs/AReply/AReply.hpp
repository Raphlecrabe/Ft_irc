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
		AReply(std::string name);
		virtual ~AReply();

		std::string &getName();
		virtual	Message getmsg(Hub &hub, Message &message) = 0; //TO DO Ajouter les params dans le getMsg
};

#endif