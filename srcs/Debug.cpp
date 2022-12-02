#include "../incs/Debug.hpp"

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>

Debug *Debug::_instance = nullptr;

Debug::Debug() : _fileName("log.txt") {
	std::ofstream file;
	
	file.open(_fileName.c_str(), std::ofstream::out | std::ofstream::trunc);

	file.close();
}

Debug::~Debug() {
	
}

void Debug::_log(std::string &m) {

	std::ofstream file(_fileName.c_str(), std::ios::app);

	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);

	try
	{
		file << m << std::endl;
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Debug::Log(std::string m) {

	if (Debug::_instance == nullptr)
		Debug::_instance = new Debug();

	Debug::_instance->_log(m);
}