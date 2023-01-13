#ifndef AREPLY_HPP
# define AREPLY_HPP

# include <iostream>
# include "../Callback.hpp"
# include "../Hub.hpp"
# include "../Debug.hpp"

class AReply {
	private:
		std::string _name;

		virtual	Message getmsg(Hub &hub, Message &message, std::string param) = 0;
	public:
		AReply(std::string name) : _name(name) {}
		virtual ~AReply() {}

		std::string 	&getName() { return this->_name; }

		void			Log() {
			Debug::Log(getName() + " called");
		}

		Message			GetMsg(Hub &hub, Message &message, std::string param) {
			Log();
			return getmsg(hub, message, param);
		}
};

#endif