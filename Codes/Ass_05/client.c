 //TCPclient to calculates the net salary of the Employee
#include <netdb.h> 
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>         
#include <stdlib.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h> 
#include <sys/socket.h> 

#define MAX 100
#define PORT 8080 
#define SA struct sockaddr 


void sendCalculation(int sockfd) 
{    
	 
	    char buff[MAX]; 
	    char buff1[MAX]; // to store expression from client
	    
	    bzero(buff,MAX);    // empty the buffer 
		
	    
	    for( ;; )
		{    
			bzero(buff1,MAX);
      		        write(sockfd ,"\n Connected...to Client", sizeof("Connected...to Client"));        // write to the stream 
        		if(strncmp("exit",buff,4) == 0 )
			{
        
		    		printf("Exiting ...\n");
		   	 	return ;
		    
			}     
			bzero(buff1,MAX);

			printf("_______________________________\n");
			printf("----Net-Salary Calculator------\n");
			printf("_______________________________\n");
	 
			printf("Enter your Salary's for example(basicsalary hra da pt epf=2000,3000,500,500,100):");
			scanf("%s",buff1);

			write(sockfd , buff1 , sizeof(buff1)); 
			bzero(buff1,MAX);

			read(sockfd,buff,sizeof(buff));

			 if (strncmp("exit", buff, 4) == 0) 
			 { 
			   	 printf("Client Exit...\n"); 
			    	 break;
			} 
			
			printf("\nyour Net-Salary is : %f\n",*((float*)buff)); 
			printf("******************************\n");    
			bzero(buff,MAX);   
	    }
} 

int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 

    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) 
    { 
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
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) 
    { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 

    // function for sending Expression 
    sendCalculation(sockfd); 

    // close the socket 
    close(sockfd); 
}
