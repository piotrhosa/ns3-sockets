#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFLEN 2000
#define BACKLOG 10
#define PORT 80

int main(){

	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddrlen = sizeof(cliaddr), servaddrlen = sizeof(servaddr);
	ssize_t i, readcount;

	char buffer[BUFFLEN];
	char message[] = "Hello yourself.";

	int messagelen = strlen(message);
	int filedesc, connfiledesc;

	filedesc = socket(AF_INET, SOCK_STREAM, 0);
	if(filedesc == -1) {
		fprintf(stderr, "Could not create socket.");
		exit(1);
	}

	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);

	if(bind(filedesc, (struct sockaddr *) &servaddr, servaddrlen) == -1) {
		fprintf(stderr, "Could not bind socket.");
		exit(1);
	}

	if(listen(filedesc, BACKLOG) == -1) {
		printf(stderr, "Could not activate socket listener.");
		exit(1);
	}
	
	connfiledesc = accept(filedesc, (struct sockaddr *) &cliaddr, &cliaddrelen);
	if(connfiledesc == -1) {
		printf(stderr, "No response from client.");
		exit(1);
	}

	//read and print
	readcount = read(connfiledesc, buffer, BUFFLEN);
	if(readcount == -1){
	  //handle error
	}
	
	for(i = 0; i < BUFLEN, ++i){
	  printf("%c", buf[i]);
	}

	if(write(connfiledesc, message, messagelen) == -1){
		//handle error
	}

	//clear buffer before next read
	bzero(buffer, BUFFLEN);

	//EOF read
	readcount = read(connfiledesc, buffer, BUFFLEN);
	if(readcount == -1) {
		//handle error
	}

	//close connection
	close(filedesc);

	//exit

	return 0;
}
