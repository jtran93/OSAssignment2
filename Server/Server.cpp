#include "Server.h"

void Server::createSocket(std::string portNumber)
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
	listen(sockfd, 10);
	
}

void Server::receiveCalls()
{
	struct sockaddr_storage their_addr;
	socklen_t addr_size;
	
	addr_size = sizeof their_addr;
	new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
}

void Server::addData(std::string textFile)
{
	std::string name;
	std::string grade;
	
	std::ifstream fin;
	fin.open(textFile.c_str());
	
	if(fin.is_open())
	{
		while(!fin.eof())
		{
			fin >> name;
			fin >> grade;
			
			nicknames.push_back(name);
			grades.push_back(grade);
		}
	}
}

void Server::printData()
{
	for(int i  = 0; i<nicknames.size(); i++)
	{
		std::cout<<nicknames[i]<<" "<<grades[i]<<"\n";
	}
}
