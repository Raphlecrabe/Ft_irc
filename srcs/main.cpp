#include "../incs/Server.hpp"
#include "../incs/ACommand/Includecommand.hpp"

int main()
{
	Server server("AwesomeIrc.com", "FT_IRC");
	server.launch();
}