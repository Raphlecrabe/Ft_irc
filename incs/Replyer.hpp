#ifndef REPLYER_HPP
# define REPLYER_HPP

# include "AReply/Includereply.hpp"

# include <vector>
# include <map>

class Replyer {
	private:
		std::map<std::string, AReply *> _Replys;
		ReplyCreator					_ReplyCreator;
		Sender							_Sender;
	public:
		Replyer();
		~Replyer();

		TreatReplys(std::vector<string> Replys, Hub hub, Message message);
		Replyone(string name, Hub hub, Message message);
};

#endif