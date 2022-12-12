#include "../incs/Server.hpp"
#include "../incs/ACommand/Includecommand.hpp"

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