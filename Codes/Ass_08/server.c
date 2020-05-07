 	#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
 
void func(int sockfd)
{
  char buff[MAX];
  FILE *file2;
   int n;
  
for(;;)
{
     bzero(buff,MAX);
      write(sockfd,"connected",sizeof("connected"));
     bzero(buff,MAX);

    read(sockfd,fopen("file1.txt","r"),sizeof(fopen("file1.txt","r")));
	if(strncmp("exit",buff,4)==0){
         printf("Server Exit ....\n");
         break;

    }
	file2 = fopen("file1.txt","r");
  if(file2 == NULL)
  {
	  printf("file is empty!!\n");
  }
  else
  {   printf("file received successfull from client\n");

     printf("1.read the file \t 2.exit server\n");
     scanf("%d",&n);

	 switch(n)
	 {
		 case 1 : printf("reading from file1.txt!\n");


	  while(fgets(buff,MAX,file2) != NULL)
	  {
		  printf("%s",buff);
	  }

	  fclose(file2);

	  break;

	  case 2 :
	          write(sockfd,"exit",sizeof("exit"));
			  printf("server exiting!!!");	
			  exit(0);
	 default : printf("please enter a valid input!!\n");


	  
	 }
	  

  }
	printf("reading file successfully!!\n");
  
   bzero(buff,MAX);
    

  
 


} 
}

int main()
{
  int sockfd,connfd,len;
  struct sockaddr_in servaddr,cli;

sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1){printf("socket fail to create ......!"); exit(0); }
else printf("socket successfully created......\n");

bzero(&servaddr,sizeof(servaddr));

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(PORT);

if ((bind(sockfd,(SA*)&servaddr,sizeof(servaddr))) !=0)
 { 
  printf("socket bind failed...\n");
  exit(0);
 }
else printf("socket bind successfully...\n");

if((listen(sockfd,5))!=0)
{
  printf("listen fail....\n");
  exit(0);
}

else printf("server listening...\n");
len=sizeof(cli);

connfd=accept(sockfd,(SA*)&cli,&len);

if(connfd<0)
{printf("server accept failed...\n");
 exit(0);
}
else 
printf("server accept successfully...\n");

func(connfd);


close(sockfd);

   
}
  
