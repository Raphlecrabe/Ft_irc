#ifndef SENDER_HPP
# define SENDER_HPP

#include <string>
#include <cstring>

class Sender {
	private:

	public:
		Sender();
		~Sender();

		void sendto(int fd, std::string msg);
};

#endif