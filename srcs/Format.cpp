#include "../incs/Format.hpp"
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>

Format::Format() {

}

Format::~Format() {
	
}

void	Format::getmsginfo(std::string msg, t_msginfo *msginfo) {
	
	int index = 0;

	if (msginfo == NULL)
		return;

	// Parsing src

	if (msg[0] == ':')
	{
		int srclen = 0;

		while (msg[1 + srclen] && msg[1 + srclen] != ' ')
			srclen++;

		msginfo->src = msg.substr(1, srclen);
		index = 1 + srclen;

	} else
		msginfo->src = "";

	while (msg[index] && msg[index] == ' ')
		index++;

	// Parsing cmd

	int cmdlen = 0;

	while (msg[index + cmdlen] && msg[index + cmdlen] != ' ')
		cmdlen++;

	msginfo->cmd = msg.substr(index, cmdlen);

	index += cmdlen;

	while (msg[index] && msg[index] == ' ')
		index++;

	// Parsing params

	int paramslen = 0;

	while (msg[index + paramslen]
		&& !(msg[index + paramslen] == '\r' && msg[index + paramslen + 1] == '\n'))
		paramslen++;
		
	msginfo->params = msg.substr(index, paramslen);
}

std::string Format::cat(t_msginfo msginfo) {
	std::string msg;

	msg = ":" + msginfo.src + " " + msginfo.cmd + " " + msginfo.params + "\r\n";

	return msg;
}

const char* Format::WrongFormatException::what() const throw() {
	return "Exception: wrong message format";
}