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
		std::map<std::string, AReply *> _Replys;
		ReplyCreator					_ReplyCreator;
		Sender							_Sender;
	public:
		Replyer();
		~Replyer();

		void	TreatReplys(std::vector<std::string> Replys, Hub hub, Message message);
		void	Replyone(std::string name, Hub hub, Message message);
};

#endif