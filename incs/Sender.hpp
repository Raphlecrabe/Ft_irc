#ifndef SENDER_HPP
# define SENDER_HPP

#include <string>
#include <cstring>

#include "Message.hpp"

class Sender {
	private:

	public:
		Sender();
		~Sender();

		void sendto(int fd, const char *datas, int size);
		void sendto(int fd, std::string msg);
		void sendto(Message &);

		class SendErrorException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoDestinationException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif