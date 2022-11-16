#ifndef REPLIER_HPP
# define REPLIER_HPP

# include "AReply.hpp"

# include <vector>
# include <map>

class Replier {
	private:
		std::map<std::string, AReply *> _dict;

	public:
		Replier(std::vector<AReply *> replies);
		~Replier();

		std::string getReplyByName(std::string);
};

#endif