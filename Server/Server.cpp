#include "Server.h"

int Server::createSocket(std::string portNumber)
{
	char hostName[256];
	
	gethostname(hostName, sizeof hostName+1);
	std::cout<<"HOSTNAME: "<<hostName<<"\n";
	
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
	
	return(sockfd);
	
}

int Server::receiveCall()
{
	struct sockaddr_storage their_addr;
	socklen_t addr_size;
	
	addr_size = sizeof their_addr;
	new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
	if(new_fd == -1)
	{	
		std::cout<<"Call was not accepted correctly\n";
	}
	
	return(new_fd);
}

std::string Server::receiveMessage()
{
	
	memset(msg,0,sizeof msg);
	byte_buffer = recv(new_fd, msg, sizeof msg, 0);
	//byte_buffer = read(new_fd, msg, sizeof msg);
	
	return std::string(msg);
}

void Server::sendMessage(std::string grade)
{
	byte_buffer = send(new_fd, grade.c_str(), sizeof grade, 0);
}

std::string Server::getGrade(std::string nickname)
{
	int notFoundGrade = 0;
	std::stringstream ss;
	
	for(int i = 0; i<nicknames.size(); i++)
	{
		if(nickname == nicknames[i])
		{
			return grades[i];
		}
	}
	
	notFoundGrade = rand()%(45) + 55;
	ss<<notFoundGrade;
	std::string str = ss.str();
	
	return str;
}

bool Server::addData(std::string textFile)
{
	std::string name;
	std::string grade;
	
	std::ifstream fin;
	fin.open(textFile.c_str());
	
	if(fin.is_open())
	{
		std::cout<<"Text file opened successfully.\n";
		while(!fin.eof())
		{
			fin >> name;
			fin >> grade;
			
			nicknames.push_back(name);
			grades.push_back(grade);
		}
	}
	else
	{
		std::cout<<"Unable to open file.\n";
		return false;
	}
	
	return true;
	
}

void Server::printData()
{
	for(int i  = 0; i<nicknames.size(); i++)
	{
		std::cout<<nicknames[i]<<" "<<grades[i]<<"\n";
	}
}















