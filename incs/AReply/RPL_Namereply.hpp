#ifndef RPL_NAMEREPLY_HPP
# define RPL_NAMEREPLY_HPP

# include "AReply.hpp"

class RPL_Namereply : public AReply{
	private:

	public:
		RPL_Namereply() : AReply("RPL_NAMEREPLY") {}
		~RPL_Namereply() {}

		Message	getmsg(Hub &hub, Message &message, std::string param) {
			Channel	*channel = hub.getChannelByName(param);

			std::string messageparam = message.getSender()->getNickname()
				+ " = " + channel->get_name() + " :";
			std::vector<User *>channelusers = channel->get_users();
			std::vector<User *>::iterator it;
			for (it = channelusers.begin(); it != channelusers.end(); it++)
			{
				if (channel->isChannelOperator(*it) == 1)
					messageparam += "@";
				messageparam += (*it)->getNickname() + " ";
			}
			Message	newmessage(hub.getServerName(), "353", messageparam);
			newmessage.addDestinator(message.getSender());
			return (newmessage);
		}
};

#endif
