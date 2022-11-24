#ifndef REPLYER_HPP
# define REPLYER_HPP

# include "AReply/Includereply.hpp"
# include <vector>
# include <map>
# include <string>
# include "ReplyCreator.hpp"
# include "Sender.hpp"
# include "Hub.hpp"
# include "Message.hpp"

class Replyer {
	private:
		ReplyCreator	_ReplyCreator;
		Sender			_Sender;
		Hub				&_hub;
	public:
		Replyer(Hub &hub);
		~Replyer();

		void	TreatReplys(Callback &callback, Message &message);
		int		Replyone(std::string &name, Message &message);
};

#endif