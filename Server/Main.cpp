#include "Server.h"

#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
	Server server;
	
	std::string nickname;
	std::string textFile;
	std::string portNumber;
	
	std::cout<<"Enter the name of the text file: ";
	std::cin>>textFile;
	server.addData(textFile);
	
	std::cout<<"Enter server port number: ";
	std::cin>>portNumber;

	server.createSocket(portNumber);
	
	while(nickname != "")
	{
		server.receiveCalls();
		
		
	}
	
	
	
	
	
	
	
	
	return 0;
}










