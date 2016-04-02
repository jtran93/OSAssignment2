#ifndef Server_h
#define Server_h

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cstring>
#include <time.h>
#include <sstream>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <netdb.h>


class Server
{
	public:
		int createSocket(std::string portNumber);
		int receiveCall();
		std::string receiveMessage();
		void sendMessage(std::string grade);
		std::string getGrade(std::string nickname);
		
		bool addData(std::string textFile);
		void printData();
	private:
		std::vector<std::string> nicknames;
		std::vector<std::string> grades;
		
		int status;
		int sockfd;
		int new_fd;
		int byte_buffer;
		char msg[2048];
		struct addrinfo hints;
		struct addrinfo *res;
};

#endif