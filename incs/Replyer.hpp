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
		Sender			&_sender;
		Hub				&_hub;
	public:
		Replyer(Sender &sender, Hub &hub);
		~Replyer();

		void	TreatReplys(Callback &callback, Message &message);
		int		Replyone(std::string &name, Message &message, std::string param);
};

#endif