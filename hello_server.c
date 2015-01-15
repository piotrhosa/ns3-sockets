#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 5000
#define BUFLEN 2000

int main() {

	struct sockaddr_in addr, cliaddr;
	socklen_t cliaddr_len = sizeof(cliaddr);

	int backlog = 10, connfiledesc;
	ssize_t i, readcount;
	char buff[BUFFLEN];

	int filedesc = socket(AF_INET, SOCK_STREAM, 0);
	if(filedesc == -1) {
		//handle error
	}

	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);

	if(bind(filedesc, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
	  printf("Could not bind socket.");
	}

	if(listen(filedesc, backlog) == -1) {
	  printf("Could not activate socket listener.");
	}
	
	connfiledesc = accept(filedesc, (struct sockaddr *) &cliaddr, &cliaddrelen);
	if(connfiledesc == -1) {
	  printf("")
	}

	//read and print
	readcount = (read, buff, BUFLEN);
	if(readcount == -1){
	  //handle error
	}
	
	for(i = 0; i < BUFLEN, ++i){
	  printf("%c", buf[i]);
	}

	//close connection
	close(filedesc);

	//exit

	return 0;
}
