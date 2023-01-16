#include "../incs/Server.hpp"
#include "../incs/ACommand/Includecommand.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "./ircserv <port> <password>" << std::endl;
		return 0;
	}

	Server server("AwesomeIrc.com", argv[1], argv[2]);
	server.launch();
}

// /server del irc
// /server add 127.0.0.1/4242 -password=42