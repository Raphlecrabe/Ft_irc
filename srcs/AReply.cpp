#include "../incs/AReply.hpp"
#include <iostream>

AReply::AReply(std::string name) : _name(name) {

}

AReply::~AReply() {
	
}

std::string AReply::getName() { return _name; }