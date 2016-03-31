#include "Server.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <netdb.h>

#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
	Server server;
	int test;
	int sockfd;
	int new_sockfd;
	int byte_buffer;
	char msg[512];
	bool txtTest = false;
	
	std::string nickname;
	std::string textFile;
	std::string portNumber;
	
	while(txtTest == false)
	{
		std::cout<<"Enter the name of the text file: ";
		std::cin>>textFile;
		txtTest = server.addData(textFile);
	}
	
	std::cout<<"Enter server port number: ";
	std::cin>>portNumber;

	sockfd = server.createSocket(portNumber);
	
	do
	{
		nickname.clear();
		new_sockfd = server.receiveCall();
		
		if(new_sockfd == -1)
		{	
			std::cout<<"Call was not accepted correctly\n";
		}

		byte_buffer = recv(new_sockfd, msg, sizeof msg, 0);
		nickname = std::string (msg);
		std::cout<<"The nickname is: "<<nickname<<"\n";
		
	}while(nickname != "");
	
	
	
	return 0;
}










