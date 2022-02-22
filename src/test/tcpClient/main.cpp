#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <arpa/inet.h> 

#define SERVER_PORT 8953
#define MAXDATASIZE 100  
#define SERVER_IP "192.168.1.6" 

int main() { 
    int sockfd; 
    struct sockaddr_in server_addr; 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(SERVER_PORT); 
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP); 
    connect(sockfd, (struct sockaddr *)&server_addr,sizeof(struct sockaddr_in));
    send(sockfd,"hello",5,0);
    close(sockfd); 
    return 0;
}