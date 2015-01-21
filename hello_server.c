#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h> //otherwise it complains about INADDR_ANY
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define BUFFLEN 2000
#define BACKLOG 10
#define PORT 5000

int main(){

	struct sockaddr_in servaddr, cliaddr;
	socklen_t servaddrlen = sizeof(servaddr), cliaddrlen = sizeof(cliaddrlen);
	ssize_t readcount;

	char buffer[BUFFLEN];
	char message[] = "Hello yourself.\n";

	int messagelen = strlen(message);
	int filedesc, connfiledesc;

	filedesc = socket(AF_INET, SOCK_STREAM, 0);
	if(filedesc == -1){
		fprintf(stderr, "Error creating socket.\n");
		exit(1);
	}

	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
    

	if(bind(filedesc, (struct sockaddr *) &servaddr, servaddrlen) == -1){
		fprintf(stderr, "Error binding socket.\n");
		exit(1);
	}
    
    while(1){

	if(listen(filedesc, BACKLOG) == -1) {
		fprintf(stderr, "Error activating socket listener.\n");
		exit(1);
	}
	
	connfiledesc = accept(filedesc, (struct sockaddr *) &cliaddr, &cliaddrlen);
	if(connfiledesc == -1) {
		fprintf(stderr, "No response from client.\n");
		exit(1);
	}

    
	readcount = read(connfiledesc, buffer, BUFFLEN);
	if(readcount == -1){
        fprintf(stderr, "Error reading client.\n");
        exit(1);
	}
		
    printf("%s", buffer);

	if(write(connfiledesc, message, messagelen) == -1){
        fprintf(stderr, "Error writing to client.\n");
        exit(1);
	}
        
    //clear buffer before next read
    bzero(buffer, BUFFLEN);
        
    }
    
    close(filedesc);

    printf("Server has been disconnected.\n");

	return 0;
}
