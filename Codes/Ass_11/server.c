#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#define PORT 4444
#define MAX 100
int main()
{
int sockfd,ret,newSocket;
struct sockaddr_in serverAddr,newAddr;
char buffer[MAX];
pid_t childpid;
socklen_t addr_size;
sockfd= socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("Error in connection\n");
exit(1);
}
printf("Server Socket is created\n");
memset(&serverAddr,'\0',sizeof(serverAddr));
serverAddr.sin_family=AF_INET;
serverAddr.sin_port=htons(PORT);
serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
ret=bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
if(ret<0)
{
printf("Error in Binding.\n");
exit(1);
}
printf("Bind to port %d\n",4444);
if(listen(sockfd,2)==0)
{
	printf("Listening...\n");
}
else
{
	printf("Error in binding.\n");
}
while(1)
{
	newSocket=accept(sockfd,(struct sockaddr*)&newAddr,&addr_size);
	if(newSocket < 0)
	{
		exit(1);
	}
	
printf("Connection accepted from %s:%d\n",inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));
if((childpid=fork())==0)
{
	close(sockfd);
	while(1)
	{
		 bzero(buffer, MAX);
		recv(newSocket,buffer,MAX,0);
		if (strncmp("exit", buffer, 4) == 0)
		{
			printf("Disconnected from %s:%d\n",inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));
			break;
		}
		else
		{
			printf("From Client: %s\n", buffer); 
			bzero(buffer, MAX);
			printf("Server:\t");
			scanf("%s",buffer);
			send(newSocket,buffer,strlen(buffer),0);
			
		}
	}
	}
}
close(newSocket);	
	return 0;
}
