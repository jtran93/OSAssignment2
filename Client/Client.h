/*
	Johnathan Tran
	Peoplesoft ID: 1078586
	Submission Date: 4/4/16
	Cosc 3360
	OSAssignment2
*/

#ifndef Client_h
#define Client_h

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cstring>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <netdb.h>


class Client
{
	public:
		int createSocket(std::string hostName, std::string portNumber);
		bool makeCall();
		std::string receiveMessage();
		void sendMessage(std::string nickname);
	private:
		int status;
		int sockfd;
		int byte_buffer;
		char msg[2048];
		struct addrinfo hints;
		struct addrinfo *res;
};

#endif