
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include<unistd.h>
#include <string.h> 
#include<arpa/inet.h>
#include <sys/socket.h> 

#include <netinet/in.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
void func(int sockfd) 
{ 
    char buff[MAX]; 
	FILE *filep;
    int n; 
    for (;;) { 
        bzero(buff, sizeof(buff)); 

	     read(sockfd,buff,sizeof(buff));

		  if(strncmp("exit",buff,4)==0){
              printf("Server Exit ....\n");
              break;

               }
		bzero(buff, sizeof(buff)); 
        printf("writing in file1.txt:"); 
        n = 0; 
        while ((buff[n++] = getchar()) != '\n') 
        ; 

		filep = fopen("file1.txt", "w");

		fputs(buff,filep);
		fputs("\n",filep);

        write(sockfd, fopen("file1.txt", "r") , sizeof(fopen("file1.txt", "r"))); 
        
		fclose(filep);

        bzero(buff, sizeof(buff)); 

		printf("file sent to server successfully\n");     
    } 
} 
  
int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 
