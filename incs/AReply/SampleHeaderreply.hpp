#ifndef NAME_HPP
# define NAME_HPP

# include "AReply.hpp"

class Name : public AReply{
	private:

	public:
		Name() : AReply("NAME") {};
		~Name() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {

			Message newmessage("source", "command", "params");
			newmessage.addDestinator(message.getSender());
			return newmessage;
		}
};

#endif