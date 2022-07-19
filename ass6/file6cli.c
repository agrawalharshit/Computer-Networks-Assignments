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
#define PORT 6500

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

    char buffer[1000];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = PORT;
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
    bzero(buffer,1000);

FILE *f;
write(sockfd,argv[2],sizeof(argv[2]));
f=fopen(argv[2],"r");
fread(buffer,1000,1,f);
write(sockfd,buffer,1000);
bzero(buffer,1000);
read(sockfd,buffer,1000);
printf("%s\n",buffer);
close(sockfd);
return 0;
}
/*OUTPUT***
bhu@bhu-Inspiron-5520:~$ cc client1.c -o c1
bhu@bhu-Inspiron-5520:~$ ./c1 192.168.0.109 test.txt
The file has been sent successfully
aman@aman-Inspiron-5520:~$ 


