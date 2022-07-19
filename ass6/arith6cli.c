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
    int n1,n2,ans,choice,yes;
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
if(choice==5)
goto T;
read(sockfd,buffer,256);
printf("%s\n",buffer);
bzero(buffer,256);
scanf("%d",&n1);
write(sockfd,&n1,sizeof(int));
read(sockfd,buffer,256);
printf("%s\n",buffer);
bzero(buffer,256);
scanf("%d",&n2);
write(sockfd,&n2,sizeof(int));
read(sockfd,&ans,sizeof(int));
printf("Server-   The Answer is : %d\n",ans);
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
/*****OUTPUT******
aman@aman-Inspiron-5520:~$ cc client3.c -o c3
aman@aman-Inspiron-5520:~$ ./c3 192.168.0.109 60005
Server-     *******CALCULATOR*******
1. ADDITION
2. SUBTRACTION
3. MULTIPLICATION
4. DIVISION
5. EXIT

ENTER  YOUR  CHOICE
1
Server-   Enter the First Number
4
Server-   Enter the Second Number
5
Server-   The Answer is : 9
Server-   Do You Want More Arithmetic(1/0)  ? 
1
Server-     *******CALCULATOR*******
1. ADDITION
2. SUBTRACTION
3. MULTIPLICATION
4. DIVISION
5. EXIT

ENTER  YOUR  CHOICE
3
Server-   Enter the First Number
6
Server-   Enter the Second Number
7
Server-   The Answer is : 42
Server-   Do You Want More Arithmetic(1/0)  ? 
0
Server-   Exited
aman@aman-Inspiron-5520:~$
