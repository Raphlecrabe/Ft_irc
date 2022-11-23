#ifndef USERCMD_HPP
# define USERCMD_HPP

# include "ACommand.hpp"
# include <iostream>

class UserCmd : public ACommand {
	private:

	public:
		UserCmd();
		~UserCmd();

		Callback	*cmdExecute(Message &, Hub &);
};

#endif
