#ifndef SENDER_HPP
# define SENDER_HPP

#include <string>
#include <cstring>
#include <map>

#include "Message.hpp"

class Sender {
	private:
		std::map<int, std::vector<std::string> > _buffers;

		void _send(int fd, std::string msg);
	public:
		Sender();
		~Sender();

		void sendto(int fd, const char *datas, int size);
		void sendto(int fd, std::string msg);
		void sendto(Message const &);

		void Speak(int fd);

		bool HasSomethingToSayTo(int fd);

		class SendErrorException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoDestinatorException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif