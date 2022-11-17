#ifndef REPLYER_HPP
# define REPLYER_HPP

# include "/AReply/AReply.hpp"

# include <vector>
# include <map>

class Replyer {
	private:
		std::map<std::string, AReply *> _Replies;
		ReplyCreator					_ReplyCreator;
		Sender							_Sender;
	public:
		Replyer();
		~Replyer();

		TreatReplys(std::vector<string> Replys, Hub hub);
		Replyone(string name, Hub hub);
};

#endif