# include "../incs/Receiver.hpp"
# include "../incs/Message.hpp"
# include "../incs/Debug.hpp"
# include <iostream>
# include <vector>

Receiver::Receiver(Sender &sender, Hub & hub) : _dispatcher(sender, hub) {

}

Receiver::~Receiver() {
	
}

void Receiver::Hear(User * user, std::string datas) {

	size_t len = datas.find("\r\n");

	while(len != std::string::npos)
	{
		std::string ndatas = datas.substr(0, len + 2);
		
		Message msg(user, ndatas);
		
		if (_dispatcher.Execute(msg) == -1)
			break;

		datas = datas.substr(len + 2);

		len = datas.find("\r\n");
	}
}