#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h> //otherwise it complains about INADDR_ANY
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT 80
#define BUFFLEN 2000

void error(char message[]){
    
    puts(message);
    exit(1);
}

int main(){

	struct sockaddr_in servaddr;
	socklen_t servaddrlen = sizeof(servaddr);
    ssize_t readcount;

	int filedesc;
    
    char message[] = "Hello server";
    int messagelen = strlen(message);
    
    char buffer[BUFFLEN];
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

	filedesc = socket(AF_INET, SOCK_STREAM, 0);
	if(filedesc == -1){
        fprintf(stderr, "Error creating socket.");
        exit(1);
	}

	if(connect(filedesc, (struct sockaddr *) &servaddr, servaddrlen) == -1){
        fprintf(stderr, "Error connecting to server.");
        exit(1);
	}
    
    //Only one loop for now
    for(int i = 0; i < 1; ++i) {
        if(write(filedesc, message, messagelen) == -1){
            fprintf(stderr, "Error writing to server.");
            exit(1);
        }
    }
    
    readcount = read(filedesc, buffer, BUFFLEN);
    if(readcount == -1){
        fprintf(stderr, "Error reading from server.");
        exit(1);
    }
    
    for(ssize_t i = 0; i < BUFFLEN; ++i){
        printf("%c", buffer[i]);
    }
    
    close(filedesc);
    
    printf("Connection was closed.");
    
}

