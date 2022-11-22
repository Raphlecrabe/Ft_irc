#ifndef RECEIVER_HPP
# define RECEIVER_HPP

# include <iostream>

class Context;
class Dispatcher;

class Receiver {
	private:
		Dispatcher _dispatcher;

	public:
		Receiver();
		~Receiver();

		void Hear(int fd, char* datas, Context &);
};

#endif