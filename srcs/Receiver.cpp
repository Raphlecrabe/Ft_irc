# include "../incs/Receiver.hpp"
# include "../incs/Message.hpp"
# include <iostream>

Receiver::Receiver() {

}

Receiver::~Receiver() {
	
}

void Receiver::Hear(int fd, char *datas, Context &) {
	User *user = new User(fd);

	Message msg(user, datas);

	//_dispatcher.Execute(msg);
}