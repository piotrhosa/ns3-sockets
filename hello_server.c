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
	socklen_t servaddrlen = sizeof(servaddr);
	ssize_t readcount;

	char buffer[BUFFLEN];
	char message[] = "Hello yourself.\n";

	int messagelen = strlen(message);
	int filedesc, connfiledesc;

	memset(&servaddr, '0', servaddrlen);
	memset(buffer, '0', BUFFLEN);

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

	if(listen(filedesc, BACKLOG) == -1) {
		fprintf(stderr, "Error activating socket listener.\n");
		exit(1);
	}
	
	connfiledesc = accept(filedesc, (struct sockaddr *) &cliaddr, sizeof(cliaddr));
	if(connfiledesc == -1) {
		fprintf(stderr, "No response from client.\n");
		exit(1);
	}

	//read and print
	readcount = read(connfiledesc, buffer, BUFFLEN);
	if(readcount == -1){
        fprintf(stderr, "Error reading client.\n");
        exit(1);
	}
	
    for(ssize_t i = 0; i < BUFFLEN; ++i){
	  printf("%c", buffer[i]);
	}

	if(write(connfiledesc, message, messagelen) == -1){
        fprintf(stderr, "Error writing to client.\n");
        exit(1);
	}

	//clear buffer before next read
	bzero(buffer, BUFFLEN);

	//EOF read
	readcount = read(connfiledesc, buffer, BUFFLEN);
	if(readcount == -1) {
        fprintf(stderr, "Error terminating connection.\n");
        exit(1);
	}

	//close connection
	close(filedesc);

	//exit

	return 0;
}
