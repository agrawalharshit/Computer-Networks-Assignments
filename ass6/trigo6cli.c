#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include<arpa/inet.h>
#include<unistd.h> 
#include<math.h>



void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server; char fname[25];
    int choice,yes;
    float angle,ans;
    char buffer[256];
    char s_num[5];
	int num;
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
A : bzero(buffer,256);
read(sockfd,buffer,256);
printf("%s\n",buffer);
bzero(buffer,256);
scanf("%d",&choice);
write(sockfd,&choice,sizeof(int));
if(choice==4)
goto T;
read(sockfd,buffer,256);
printf("%s\n",buffer);
bzero(buffer,256);
scanf("%f",&angle);
write(sockfd,&angle,sizeof(float));

read(sockfd,&ans,sizeof(float));
//ans=round(ans);
printf("Server-   The Answer is : %.2f\n",ans);
read(sockfd,buffer,256);
printf("%s\n",buffer);
scanf("%d",&yes);
write(sockfd,&yes,sizeof(int));
if(yes==1)
goto A;

T : 	bzero(buffer,256);
	read(sockfd,buffer,256);
	printf("%s",buffer);
	close(sockfd);
return 0;
}
/****OUTPUT******
aman@aman-Inspiron-5520:~$ cc client4.c -o c4 -lm
aman@aman-Inspiron-5520:~$ ./c4 192.168.0.109 65009
Server-     *******TRIGO - CALCULATOR*******
1. SINE
2. COSINE
3. TANGENT
4. EXIT

ENTER  YOUR  CHOICE
1
Server-   Enter the ANGLE
60
Server-   The Answer is : 0.87
Server-   Do You Want More Calculation(1/0)  ? 
1
Server-     *******TRIGO - CALCULATOR*******
1. SINE
2. COSINE
3. TANGENT
4. EXIT

ENTER  YOUR  CHOICE
2
Server-   Enter the ANGLE
60
Server-   The Answer is : 0.50
Server-   Do You Want More Calculation(1/0)  ? 
1
Server-     *******TRIGO - CALCULATOR*******
1. SINE
2. COSINE
3. TANGENT
4. EXIT

ENTER  YOUR  CHOICE
3
Server-   Enter the ANGLE
60
Server-   The Answer is : 1.73
Server-   Do You Want More Calculation(1/0)  ? 
1
Server-     *******TRIGO - CALCULATOR*******
1. SINE
2. COSINE
3. TANGENT
4. EXIT

ENTER  YOUR  CHOICE
2
Server-   Enter the ANGLE
90
Server-   The Answer is : 0.00
Server-   Do You Want More Calculation(1/0)  ? 
1
Server-     *******TRIGO - CALCULATOR*******
1. SINE
2. COSINE
3. TANGENT
4. EXIT

ENTER  YOUR  CHOICE
4
Server-   Exited
aman@aman-Inspiron-5520:~$
