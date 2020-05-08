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
int ClientSocket,ret;
struct sockaddr_in serverAddr;
char buffer[MAX];
ClientSocket= socket(AF_INET,SOCK_STREAM,0);
if(ClientSocket<0)
{
printf("Error in connection\n");
exit(1);
}
printf("Client Socket is created\n");
memset(&serverAddr,'\0',sizeof(serverAddr));
serverAddr.sin_family=AF_INET;
serverAddr.sin_port=htons(PORT);
serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
ret=connect(ClientSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
if(ret<0)
{
printf("Error in connection.\n");
exit(1);
}
printf("Connected to server\n");
while(1)
{
bzero(buffer, sizeof(buffer));
printf("Client:\t");
scanf("%s",buffer);
send(ClientSocket,buffer,strlen(buffer),0);
bzero(buffer, sizeof(buffer)); 
if (strncmp("exit", buffer, 4) == 0)
{
printf("Disconnected from server.\n");
exit(1);
}
if(recv(ClientSocket,buffer,MAX,0)<0)
{
printf("Error in receiving data\n");
}
else
{
printf("From Server:\t%s\n",buffer);
}

}
return 0;
}
