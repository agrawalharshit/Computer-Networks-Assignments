#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include<math.h>
#define PI  3.14159

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
     int n,choice,yes;
     float angle,ans;
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

S : strcpy(menu,"Server-     *******TRIGO - CALCULATOR*******\n1. SINE\n2. COSINE\n3. TANGENT\n4. EXIT\n\nENTER  YOUR  CHOICE");
write(newsockfd,menu,strlen(menu));
read(newsockfd,&choice,sizeof(int));
printf("Client-   The choice is : %d\n",choice);
if(choice==4)
goto M;
write(newsockfd,"Server-   Enter the ANGLE",strlen("Server-   Enter the ANGLE"));
read(newsockfd,&angle,sizeof(float));
printf("Client-   Angle  is : %f\n",angle);

M : 
switch(choice)
{
	case 1:
		ans=sin((angle/180)*PI);
		break;
	case 2:
		ans=cos((angle/180)*PI);
		break;
	case 3:
		ans=tan((angle/180)*PI);
		break;
	case 4:
		goto Q;
		break;
}
write(newsockfd,&ans,sizeof(float));
write(newsockfd,"Server-   Do You Want More Calculation(1/0)  ? ",strlen("Server-   Do You Want More Calculation(1/0)  ? "));
read(newsockfd,&yes,sizeof(int));
if(yes==1)
{
printf("Client-   I want  More Calculation \n");
goto S;
}

Q :	write(newsockfd,"Server-   Exited\n",strlen("Server-   Exited\n"));
	printf("Client-   Exited\n");
	close(newsockfd);
	close(sockfd);

return 0; 
}
/*****OUTPUT*******
aman@aman-Inspiron-5520:~$ cc server4.c -o s4 -lm
aman@aman-Inspiron-5520:~$ ./s4 65009
Client-   The choice is : 1
Client-   Angle  is : 60.000000
Client-   I want  More Calculation 
Client-   The choice is : 2
Client-   Angle  is : 60.000000
Client-   I want  More Calculation 
Client-   The choice is : 3
Client-   Angle  is : 60.000000
Client-   I want  More Calculation 
Client-   The choice is : 2
Client-   Angle  is : 90.000000
Client-   I want  More Calculation 
Client-   The choice is : 4
Client-   Exited
aman@aman-Inspiron-5520:~$ 

