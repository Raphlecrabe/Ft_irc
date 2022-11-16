#include "incs/Server.hpp"

int main()
{
	Server server(5);

	server.init();
	server.launch();
}