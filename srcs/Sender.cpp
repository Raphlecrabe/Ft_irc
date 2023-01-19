#include "../incs/Debug.hpp"
#include "../incs/Sender.hpp"
#include "../incs/Message.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <errno.h>
#include <sstream>

#include <sys/types.h>
#include <sys/socket.h>

Sender::Sender() {

}

Sender::~Sender() {
	
}

bool Sender::HasSomethingToSayTo(int fd) {
	if (_buffers.count(fd) == 0 || _buffers[fd].size() == 0)
		return false;
	return true;
}

void Sender::Speak(int fd) {

	if (HasSomethingToSayTo(fd) == false)
		return;

	std::vector<std::string>::iterator it;

	int sent = _send(fd, _buffers[fd][0]);

	if (sent == -1)
		return;

	_buffers[fd][0] = _buffers[fd][0].substr(sent);
	if (_buffers[fd][0] == "")
		_buffers[fd].erase(_buffers[fd].begin());
}

int Sender::_send(int fd, std::string msg) {

	int 			res;

	unsigned int	size = msg.size();
	const char* 	datas = msg.c_str();

	res = send(fd, datas, size, 0);
	Debug::Log << "Sender: sent to fd: " << fd << ": " << msg.substr(0, res);

	if (res == -1)
	{
		Debug::Log << "Sender::SendErrorException" << std::endl;
		throw Sender::SendErrorException();
		return -1;
	}

	return res;
}

void Sender::sendto(int fd, const char *datas, int size) {
	//Stays only for compatibility
	(void)size;
	sendto(fd, std::string(datas));

	return;
}

void Sender::sendto(int fd, std::string msg) {

	if (_buffers.count(fd) == 0) {
		std::vector<std::string> datas;
		std::pair<int, std::vector<std::string> > newpair(fd, datas);
		_buffers.insert(newpair);
	}

	_buffers[fd].push_back(std::string(msg));
}

void Sender::sendto(Message const & msg) {

	std::vector<User *> const destinators = msg.getDestinators();
	
	if (destinators.size() == 0)
	{
		throw Sender::NoDestinatorException();
		return;
	}

	std::vector<User *>::const_iterator it;

	for (it = destinators.begin(); it != destinators.end(); it++)
	{
		int	destfd = (*it)->getFd();
		std::string str = msg.Format();
		Debug::Log << "Sender: adding new destinator to mst " << str;
		sendto(destfd, str);
	}

}

const char* Sender::SendErrorException::what() const throw() {
	return "Sender exception: <send> returned an error";
}

const char* Sender::NoDestinatorException::what() const throw() {
	return "Sender: no destinator specified";
}