#ifndef RECEIVER_HPP
# define RECEIVER_HPP

# include <iostream>

# include "User.hpp"
# include "Dispatcher.hpp"

class Context;

class Receiver {
	private:
		Dispatcher _dispatcher;

	public:
		Receiver(Hub &);
		~Receiver();

		void Hear(User *, std::string datas);
};

#endif