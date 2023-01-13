#ifndef RPL_LIST_HPP
# define RPL_LIST_HPP

# include "AReply.hpp"

class RPL_List : public AReply{
	private:

	public:
		RPL_List() : AReply("RPL_LIST") {};
		~RPL_List() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			std::string messageparam = message.getSender()->getNickname() + " "
				+ hub.getChannelByName(param)->get_name();
			messageparam += " " + std::to_string(hub.getChannelByName(param)->get_users().size());
			if (hub.getChannelByName(param)->get_topic().size() == 0)
				messageparam += " :No Topic set";
			else
				messageparam += hub.getChannelByName(param)->get_topic();
			Message newmessage(hub.getServerName(), "322", messageparam);
			newmessage.addDestinator(message.getSender());

			return newmessage;
		}
};

#endif
