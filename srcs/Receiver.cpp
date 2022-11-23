# include "../incs/Receiver.hpp"
# include "../incs/Message.hpp"
# include <iostream>

Receiver::Receiver() {

}

Receiver::~Receiver() {
	
}

void Receiver::Hear(User const & user, char *datas, Context &) {
	Message msg(user, datas);

	//_dispatcher.Execute(msg);
}