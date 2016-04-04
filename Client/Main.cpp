#include "Client.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <netdb.h>

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

int main()
{
	Client client;
	
	bool test = false;
	int sockfd;
	int j;
	
	std::stringstream ss;
	std::string hostName;
	std::string portNumber;
	std::string nickname;
	std::string grade;

	
	while (test == false)
	{
		std::cout<<"Enter a server host name: ";
		std::cin>>hostName;
		std::cout<<"Enter a server port number (>= 1024): ";
		std::cin>>portNumber;
		
		std::istringstream(portNumber) >> j;
		
		if(j < 1024)
		{
			std::cout<<"Port number must be >= 1024.\n";
		}
		else
		{
			sockfd = client.createSocket(hostName, portNumber);
			test = client.makeCall();
		}
	}
	
	std::cin.ignore();
	do
	{
		nickname.clear();
		grade.clear();
		
		std::cout<<"Enter a student nickname: ";
		getline(std::cin, nickname);
		if(!nickname.empty())
		{
			client.sendMessage(nickname);
			grade = client.receiveMessage();
			std::cout<<"Student "<<nickname.c_str()<<" got "<<grade<<" on the quiz.\n";
			close(sockfd);
			sockfd = client.createSocket(hostName, portNumber);
			client.makeCall();
		}
		else
		{
			std::cout<<"Client has been terminated\n";
		}

	}while(!nickname.empty());
	
	
	
	return 0;
}








