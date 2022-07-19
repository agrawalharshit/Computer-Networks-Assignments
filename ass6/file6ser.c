#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#define PORT 6500

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[1000];char fname[25];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 1) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = PORT;
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
     bzero(buffer,1000);
  
FILE *fp;
read(newsockfd,fname,sizeof(fname));
fp=fopen(fname,"w");
read(newsockfd,buffer,1000);
fwrite(buffer,strlen(buffer),1,fp);
write(newsockfd,"The file has been sent successfully",30);
printf("The contents of the file are  : \n\n");
printf("%s\n",buffer);
close(fp);
close(newsockfd);
close(sockfd);
return 0; 
}
/*OUTPUT
aman@aman-Inspiron-5520:~$ ./s1
The contents of the file are  : 

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

aman@aman-Inspiron-5520:~$ 
*/

