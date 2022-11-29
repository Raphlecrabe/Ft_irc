#include "incs/Server.hpp"

int main()
{
	Server server("AwesomeIrc.com", "FT_IRC");
	
	server.launch();
}