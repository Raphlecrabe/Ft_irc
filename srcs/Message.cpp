#include "../incs/Message.hpp"
#include "../incs/User.hpp"
#include <iostream>
#include <string>
#include <cstring>

Message::Message(std::string src, std::string cmd, std::string prms) :
					_source(src), _command(cmd), _params(prms) {

}

Message::Message(char *raw) {
	std::string datas = raw;
	
	int index = 0;

	// Parsing src

	if (datas[0] == ':')
	{
		int srclen = 0;

		while (datas[1 + srclen] && datas[1 + srclen] != ' ')
			srclen++;

		this->_source = datas.substr(1, srclen);
		index = 1 + srclen;

	} else
		this->_source = "";

	while (datas[index] && datas[index] == ' ')
		index++;

	// Parsing cmd

	int cmdlen = 0;

	while (datas[index + cmdlen] && datas[index + cmdlen] != ' ')
		cmdlen++;

	this->_command = datas.substr(index, cmdlen);

	index += cmdlen;

	while (datas[index] && datas[index] == ' ')
		index++;

	// Parsing params

	int paramslen = 0;

	while (datas[index + paramslen]
		&& !(datas[index + paramslen] == '\r' && datas[index + paramslen + 1] == '\n'))
		paramslen++;
		
	this->_params = datas.substr(index, paramslen);
}

Message::Message(Message const & cpy) {
	*this = cpy;
}

Message & Message::operator=(Message const & rhs) {
	this->_source = rhs._source;
	this->_command = rhs._command;
	this->_params = rhs._params;

	this->destinator = rhs.destinator;
	return *this;
}

Message::~Message() {
	
}

std::string Message::Format() {
	std::string msg;

	msg = ":" + this->_source + " " + this->_command + " " + this->_params + "\r\n";

	return msg;
}