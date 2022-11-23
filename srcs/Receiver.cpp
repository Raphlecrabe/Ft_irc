# include "../incs/Receiver.hpp"
# include "../incs/Message.hpp"
# include <iostream>

Receiver::Receiver(Hub & hub) : _dispatcher(hub) {

}

Receiver::~Receiver() {
	
}

void Receiver::Hear(User const & user, std::string datas) {
	Message msg(user, datas);

	_dispatcher.Execute(msg);
}