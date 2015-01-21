#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h> //otherwise it complains about INADDR_ANY
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT 5000
#define BUFFLEN 2000

int main(){
  
    struct sockaddr_in servaddr;
    socklen_t servaddrlen = sizeof(servaddr);
    ssize_t readcount;

    int filedesc;
    char buffer[BUFFLEN];
    
    char message[] = "Hello server.\n";
    int messagelen = strlen(message);
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

	filedesc = socket(AF_INET, SOCK_STREAM, 0);
	if(filedesc == -1){
        fprintf(stderr, "Error creating socket.\n");
        exit(1);
	}

	if(connect(filedesc, (struct sockaddr *) &servaddr, servaddrlen) == -1){
        fprintf(stderr, "Error connecting to server.\n");
        exit(1);
	}
    
    //Only one loop for now
    for(int i = 0; i < 2; ++i) {
        if(write(filedesc, message, messagelen) == -1){
            fprintf(stderr, "Error writing to server &d.\n");
            exit(1);
        }
        
        strcpy(message, "Hello again.\n");
        
        /*
        readcount = read(filedesc, buffer, BUFFLEN);
        if(readcount == -1){
            fprintf(stderr, "Error reading from server.\n");
            exit(1);
        }
        
        printf("%s", buffer);
        */
        
    }
    
    close(filedesc);
    
    printf("Client has been disconnected.\n");
    
    return 0;
    
}

