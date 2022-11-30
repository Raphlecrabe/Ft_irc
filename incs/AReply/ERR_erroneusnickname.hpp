#ifndef ERR_ERRONEUSNICKNAME_HPP
# define ERR_ERRONEUSNICKNAME_HPP

# include "AReply.hpp"

class ERR_erroneusnickname : public AReply{
	private:

	public:
		ERR_erroneusnickname();
		~ERR_erroneusnickname();

		Message	getmsg(Hub &hub, Message &message, std::string param);
};

#endif