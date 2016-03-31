#include "Client.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <netdb.h>

#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
	Client client;
	
	int test;
	int sockfd;
	int byte_buffer;
	
	char msg[512];
	
	std::string hostName;
	std::string portNumber;
	std::string nickname;
	
	std::cout<<"Enter a server host name: ";
	std::cin>>hostName;
	std::cout<<"Enter a server port number: ";
	std::cin>>portNumber;
	
	sockfd = client.createSocket(hostName, portNumber);
	
	do
	{
		test = client.makeCall();
		if(test == -1)
		{
			std::cout<<"Could not connect call.\n";
		}
		
		std::cout<<"Enter a student nickname: ";
		std::cin>>nickname;
		
		byte_buffer = send(sockfd, nickname.c_str(), sizeof nickname, 0);
		std::cout<<"Byte Buffer: "<<byte_buffer<<" Len: "<<sizeof nickname<<"\n";
		//byte_buffer = recv(sockfd, msg, sizeof msg, 0);
		
		test = shutdown(sockfd, 2);
		if(test == 0)
		{
			std::cout<<"Close successful\n";
		}else 
		{std::cout<<"Did not close\n";}
	}while(nickname != "");
	
	
	
	
	
	return 0;
}








