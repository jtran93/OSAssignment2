#include "Client.h"

int Client::createSocket(std::string hostname, std::string portNumber)
{
	char hostName[256];
	
	gethostname(hostName, sizeof hostName+1);
	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	
	status = getaddrinfo(hostName, portNumber.c_str(), &hints, &res);
	if(status > 0)
	{
		std::cout<<"getaddrinfo error: "<<gai_strerror(status)<<"\n";
	}
	
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	
	return(sockfd);
	
}

int Client::makeCall()
{
	int call;
	
	call = connect(sockfd, res->ai_addr, res->ai_addrlen);
	if (call < 0)
	{}
	else
		std::cout<<"Call was successful\n";
	return call;
	
}






















