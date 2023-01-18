#ifndef MODE_HPP
# define MODE_HPP

# include "ACommand.hpp"

class Mode : public ACommand{
	private:

		bool 		isValid(Message &, Hub &);
		void		executeModes(char modeset, std::string modeflag, std::string modeparams, Channel *channel, Hub &);
		void		clientLimitChannel(char modeset, int limit, Channel *, Hub &);
		void		addNewOperator(char modeset, User *user, Channel *, Hub &);

	public:
		Mode();
		~Mode();

		Callback	&cmdExecute(Message &message, Hub &hub);

};

#endif