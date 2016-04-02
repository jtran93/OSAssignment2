#include "Client.h"

int Client::createSocket(std::string hostname, std::string portNumber)
{
	char hostName[256];
	
	gethostname(hostName, sizeof hostName+1);
	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	
	status = getaddrinfo(hostname.c_str(), portNumber.c_str(), &hints, &res);
	if(status != 0)
	{
		std::cout<<"getaddrinfo error: "<<gai_strerror(status)<<"\n";
	}
	
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	
	return(sockfd);
	
}

bool Client::makeCall()
{
	int call;
	
	call = connect(sockfd, res->ai_addr, res->ai_addrlen);
	if (call == -1)
	{
		std::cout<<"Could not connect call. Please try again.\n";
		return false;
	}
	else
	{
		//std::cout<<"Call was successful\n";
		return true;
	}
	
}

std::string Client::receiveMessage()
{
	byte_buffer = recv(sockfd, msg, sizeof msg, 0);
	
	return std::string(msg);
}

void Client::sendMessage(std::string nickname)
{
	byte_buffer = send(sockfd, nickname.c_str(), nickname.size(), 0);
	//byte_buffer = write(sockfd, msg, sizeof m);
}




















