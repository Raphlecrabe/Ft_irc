#ifndef MOTD_HPP
# define MOTD_HPP

# include "ACommand.hpp"

class Motd : public ACommand{
	private:
		
	public:
		Motd();
		~Motd();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
