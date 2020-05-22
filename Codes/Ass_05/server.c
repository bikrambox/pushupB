// TCPserver  to calculates the net salary of the Employee

#include <stdlib.h> 
#include <stdio.h> 
#include <netdb.h> 
#include <unistd.h>
#include <math.h>
#include <netinet/in.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 



#define MAX 100
#define PORT 8080 
#define SA struct sockaddr 
int len;
struct sockaddr_in servaddr, cli;
 

 
void doCalculation(int sockfd) 

{    
     
    	char buff1[MAX],buff[MAX];     // to store message from client 
                 
    	float a ,b,c,d,e,res;
     
      
   	 for( ;; ) // infinite loop
     
   	 {   
         
     	   a =0;b=0;c=0;d=0;e=0;
           res=0.0;

   	   if ( read(sockfd, buff, sizeof(buff) ) == 0 )
	   {
        
            	printf(" --- Failed To Read \n --- Maybe Socket Is Closed .. \n --  Exiting \n ");
            	return;
        
           }
      
    	    printf("%s\n",buff);//connected..to clent msg
     	    bzero(buff, MAX);     
 
 
	    recvfrom(sockfd,(char *)buff,MAX,MSG_WAITALL,(struct sockaddr *)&cli,&len);
	    if (strncmp("exit", buff, 4) == 0) 
            { 
		    printf("Server Exit...\n"); 
		    write(sockfd,"exit",sizeof("exit"));
		    break;
       	    } 
        
 	    sscanf( buff ,"%f,%f,%f,%f,%f", &a,&b,&c,&d,&e);
   
 	    bzero(buff, MAX); 
  	    printf("-------------------------------------\n");
       	    printf("\nBasic-Salary \t: %f\nHRA  \t\t: %f\nDA  \t\t: %f\nPT  \t\t: %f\nEPF  \t\t: %f\n",a,b,c,d,e);
   	    res=a+b+c-d-e;
	    printf("--------------------------------------\n");
    	    printf("Salary \t\t: %f",res);
	    printf("\n______________________________________\n");
    	    write(sockfd,&res,sizeof(res));
	}
}

 
int main() 
{ 
	    int sockfd, connfd;                // create socket file descriptor 
	            

	    // socket create and verification 
	    sockfd = socket(AF_INET, SOCK_STREAM, 0);             // creating a TCP socket ( SOCK_STREAM )
	    
	    if (sockfd == -1)
	    { 
		printf("socket creation failed...\n"); 
		exit(0); 
	    } 
	    else
		printf("Socket successfully created..\n"); 
	    
	     
	    bzero(&servaddr, sizeof(servaddr)); 

	    // assign IP, PORT 
	    servaddr.sin_family = AF_INET;                    // specifies address family with IPv4 Protocol 
	    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);     // binds to any address
	    servaddr.sin_port = htons(PORT);                 // binds to PORT specified

	    // Binding newly created socket to given IP and verification 
	    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) 
	    { 
		printf("socket bind failed...\n"); 
		exit(0); 
	    } 
	    else
		printf("Socket successfully binded..\n"); 

	    // Now server is ready to listen and verification 
	    if ((listen(sockfd, 5)) != 0) 
	    { 
		printf("Listen failed...\n"); 
		exit(0); 
	    } 
	    else
	    printf("Server listening..\n"); 
	    
	    len = sizeof(cli); 

	    // Accept the data packet from client and verification 
	    connfd = accept(sockfd, (SA*)&cli, &len);     // accepts connection from socket
	    
	    if (connfd < 0) 
	    { 
		printf("server acccept failed...\n"); 
		exit(0); 
	    } 
	    else
		printf("server acccept the client...\n"); 

	    // Function for recieving Expression and 
	    doCalculation(connfd); 

	    // After transfer close the socket 
	    close(sockfd); 
	    return 0;
}
