#include "../incs/Debug.hpp"

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <sys/time.h>

Debug *Debug::_instance = NULL;

Debug::Debug() : _fileName("log.txt") {
	std::ofstream file;
	
	file.open(_fileName.c_str(), std::ofstream::out | std::ofstream::trunc);

	file.close();

	struct timeval tp;
	gettimeofday(&tp, NULL);
	this->_startTime = tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

Debug::~Debug() {
	
}

void Debug::_log(std::string &m) {

	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int currentTime = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	long int timestamp = currentTime - this->_startTime;

	std::ofstream file(_fileName.c_str(), std::ios::app);

	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);

	try
	{
		file << "[" << timestamp << "] ";
		file << m;
		if (m[m.size() - 1] != '\n')
			file << std::endl;
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Debug::Log(std::string m) {

	if (Debug::_instance == NULL)
		Debug::_instance = new Debug();

	Debug::_instance->_log(m);
}