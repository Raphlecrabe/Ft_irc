#ifndef MODE_HPP
# define MODE_HPP

# include "ACommand.hpp"

class Mode : public ACommand{
	private:

		void		executeModes(char modeset, std::string modeflag, std::string modeparams, Channel *channel);
		void		clientLimitChannel(char modeset, int limit, Channel *);

	public:
		Mode();
		~Mode();

		Callback	&cmdExecute(Message &message, Hub &hub);

};

#endif