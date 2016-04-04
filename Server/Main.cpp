/*
	Johnathan Tran
	Peoplesoft ID: 1078586
	Submission Date: 4/4/16
	Cosc 3360
	OSAssignment2
*/

#include "Server.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <netdb.h>

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <sstream>

int main()
{
	srand(time(NULL));
	
	Server server;
	
	bool test = false;
	
	int j;
	
	std::string nickname = " ";
	std::string grade;
	std::string textFile;
	std::string portNumber;
	
	while(test == false)
	{
		std::cout<<"Enter the name of the text file (include .txt extension): ";
		std::cin>>textFile;
		test = server.addData(textFile);
	}
	
	test = false;
	
	while(test == false)
	{
		std::cout<<"Enter server port number (>= 1024): ";
		std::cin>>portNumber;
		std::istringstream(portNumber) >> j;
		if(j < 1024)
		{
			std::cout<<"Port number must be >= 1024.\n";
		}
		else
			test = true;
	}
	
	server.createSocket(portNumber);
	
	while(!nickname.empty())
	{
		nickname.clear();
		grade.clear();
		
		server.receiveCall();
		nickname = server.receiveMessage();
		if(!nickname.empty())
		{
			grade = server.getGrade(nickname);
			server.sendMessage(grade);
			std::cout<<"The nickname is: "<<nickname<<"\n";
			std::cout<<"Student "<<nickname<<" got "<<grade<<" on the quiz.\n";
		}
		else
		{
			std::cout<<"Client has closed connection\n";
		}
	}
	
	
	
	return 0;
}










