#include "../incs/Sender.hpp"
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <poll.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <cstring>

Sender::Sender() {

}

Sender::~Sender() {
	
}

void Sender::sendto(int fd, std::string msg) {

	if (send(fd, msg.c_str(), msg.size() + 1, 0) == -1)
		std::cerr << "error: send" << std::endl;
}