#ifndef JOIN_HPP
# define JOIN_HPP

# include "ACommand.hpp"

class Join : public ACommand{
	private:

	public:
		Join();
		~Join();

		Callback	&cmdExecute(Message &message, Hub &hub);
		void		addReplys(std::string &param);
		int			addChannel(Hub &hub, Message &message, std::string &param);
		int			joinChannel(Channel *channel, Message &message, std::string param);
		int			checkparams(Message &message);
};

#endif