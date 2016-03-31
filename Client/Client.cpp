#include "Client.h"

void Client::createSocket(std::string portNumber)
{
	char hostName[128];
	
	gethostname(hostName, sizeof hostName);
	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	
	status = getaddrinfo(hostName, portNumber.c_str(), &hints, &res);
	if(status != 0)
	{
		std::cout<<"getaddrinfo error: "<<gai_strerror(status)<<"\n";
	}
	
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	
	bind(sockfd, res->ai_addr, res->ai_addrlen);
	
}