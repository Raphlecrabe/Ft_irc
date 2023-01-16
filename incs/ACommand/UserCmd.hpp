#ifndef USERCMD_HPP
# define USERCMD_HPP

# include "ACommand.hpp"
# include <iostream>

class UserCmd : public ACommand {
	private:
		bool	checkRegisterState(User *);
		bool	checkAuthentication(User *);
		void	registerUser(User *, Message &);	

	public:
		UserCmd();
		~UserCmd();

		Callback	&cmdExecute(Message &, Hub &);
};

#endif
