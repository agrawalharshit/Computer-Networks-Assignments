#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen; 
     char menu[100]="NO VALUE";
     char buffer[256],m[5];
     struct sockaddr_in serv_addr, cli_addr;
     int n,n1,n2,ans,choice,yes;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     bzero(buffer,256);

S : strcpy(menu,"Server-     *******CALCULATOR*******\n1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n5. EXIT\n\nENTER  YOUR  CHOICE");
write(newsockfd,menu,strlen(menu));
read(newsockfd,&choice,sizeof(int));
printf("Client-   The choice is : %d\n",choice);
if(choice==5)
goto M;
write(newsockfd,"Server-   Enter the First Number",strlen("Server-   Enter the First Number : "));
read(newsockfd,&n1,sizeof(int));
printf("Client-   First Number  is : %d\n",n1);
write(newsockfd,"Server-   Enter the Second Number",strlen("Server-   Enter the Second Number : "));
read(newsockfd,&n2,sizeof(int));
printf("Client-   Second  Number  is : %d\n",n2);
M : 
switch(choice)
{
	case 1:
		ans=n1+n2;
		break;
	case 2:
		ans=n1-n2;
		break;
	case 3:
		ans=n1*n2;
		break;
	case 4:
		ans=n1/n2;
		break;
	case 5:
		goto Q;
		break;
}
write(newsockfd,&ans,sizeof(int));
write(newsockfd,"Server-   Do You Want More Arithmetic(1/0)  ? ",strlen("Server-   Do You Want More Arithmetic(1/0)  ? "));
read(newsockfd,&yes,sizeof(int));
if(yes==1)
{
printf("Client-   I want  More Arithmetic \n");
goto S;
}

Q :	write(newsockfd,"Server-   Exited\n",strlen("Server-   Exited\n"));
	printf("Client-   Exited\n");
	close(newsockfd);
	close(sockfd);

return 0; 
}
/****OUTPUT******
aman@aman-Inspiron-5520:~$ cc server3.c -o s3
aman@aman-Inspiron-5520:~$ ./s3 60005
Client-   The choice is : 1
Client-   First Number  is : 4
Client-   Second  Number  is : 5
Client-   I want  More Arithmetic 
Client-   The choice is : 3
Client-   First Number  is : 6
Client-   Second  Number  is : 7
Client-   Exited
aman@aman-Inspiron-5520:~$ 

