#include "../incs/Message.hpp"
#include "../incs/User.hpp"
#include <iostream>
#include <string>
#include <cstring>

Message::Message(std::string src, std::string cmd, std::string prms) : _source(src), _command(cmd), _params(prms)
{
}

Message::Message(User *sender, std::string raw) : _sender(sender)
{
	parse(raw);
}

Message::Message(Message const &cpy) : _sender(cpy._sender)
{
	*this = cpy;
}

Message &Message::operator=(Message const &rhs)
{
	this->_sender = rhs._sender;

	this->_source = rhs._source;
	this->_command = rhs._command;
	this->_params = rhs._params;
	this->_paramlist = rhs._paramlist;

	this->_destinators = rhs._destinators;
	return *this;
}

Message::~Message()
{
}

std::string Message::Format() const
{
	std::string msg;

	msg = ":" + this->_source + " " + this->_command + " " + this->_params + "\r\n";

	return msg;
}

void Message::parse(std::string datas)
{
	int index = 0;

	// Parsing src

	if (datas[0] == ':')
	{
		int srclen = 0;

		while (datas[1 + srclen] && datas[1 + srclen] != ' ')
			srclen++;

		this->_source = datas.substr(1, srclen);
		index = 1 + srclen;
	}
	else
		this->_source = "";

	while (datas[index] && datas[index] == ' ')
		index++;

	// Parsing cmd

	int cmdlen = 0;

	while (datas[index + cmdlen] && Utils::isBetween(datas[index + cmdlen], 32, 126) && datas[index + cmdlen] != ' ')
		cmdlen++;

	this->_command = datas.substr(index, cmdlen);

	index += cmdlen;

	while (datas[index] && datas[index] == ' ')
		index++;

	// Parsing params

	int paramslen = 0;

	while (datas[index + paramslen] && (datas.compare(index + paramslen, 2, "\r\n") != 0))
		paramslen++;

	this->_params = datas.substr(index, paramslen);

	parseparams();
}

void Message::parseparams()
{
	std::string params = this->_params;
	int i = 0;

	while (params[0] && params[0] != ':')
	{
		i = 0;

		while (params[i] == ' ')
		{
			i++;
		}

		params = params.substr(i);
		i = 0;

		if (params[0] == ':')
			break;

		while (params[i] && params[i] != ' ')
		{
			i++;
		}

		std::string p = params.substr(0, i);
		this->_paramlist.push_back(p);

		params = params.substr(i);
	}

	if (params[0] == ':')
	{
		int len = this->_params.length() - 1;
		std::string lastparam = params.substr(1, len);
		this->_paramlist.push_back(lastparam);
	}
}

void Message::addDestinator(User *dest)
{
	_destinators.push_back(dest);
}

std::string const &Message::getSource() const { return this->_source; }
std::string const &Message::getCommand() const { return this->_command; }
std::string const &Message::getParams() const { return this->_params; }
std::vector<std::string> const &Message::getParamList() const { return this->_paramlist; }
std::vector<User *> const &Message::getDestinators() const { return this->_destinators; }

User *Message::getSender() { return this->_sender; }