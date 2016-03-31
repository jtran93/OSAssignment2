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
		int makeCall();
	private:
		int status;
		int sockfd;
		struct addrinfo hints;
		struct addrinfo *res;
};

#endif