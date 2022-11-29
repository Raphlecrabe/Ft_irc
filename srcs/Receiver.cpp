# include "../incs/Receiver.hpp"
# include "../incs/Message.hpp"
# include <iostream>

Receiver::Receiver(Hub & hub) : _dispatcher(hub) {

}

Receiver::~Receiver() {
	
}

void Receiver::Hear(User * user, std::string datas) {
	//split line
	
	Message msg(user, datas);

	_dispatcher.Execute(msg);
}