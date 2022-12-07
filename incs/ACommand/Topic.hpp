#ifndef TOPIC_HPP
# define TOPIC_HPP

# include "ACommand.hpp"

class Topic : public ACommand{
	private:

	public:
		Topic();
		~Topic();

		Callback	&cmdExecute(Message &message, Hub &hub);
};

#endif
