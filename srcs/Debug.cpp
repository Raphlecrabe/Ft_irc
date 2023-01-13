#include "../incs/Debug.hpp"

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <sys/time.h>

std::ofstream Debug::Log("log.txt", std::ios::app);

Debug::Debug() {

}

Debug::~Debug() {
	
}