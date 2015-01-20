#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 80

int main(){

	struct sockaddr_in servaddr, cliaddr;
	socklen_t servaddrlen = sizeof(servaddr), cliaddrlen = sizeof(cliaddrlen);

	int filedesc, connfiledesc;

	filedesc = socket(AF_INET, SOCK_STREAM, 0);
	if(filedesc == -1){
		//handle error
	}

	if(connect(fd, (struct sockaddr *) &servaddr, servaddrlen) == -1){
		//handle error
	}



	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);

}

