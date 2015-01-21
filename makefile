all: server client


client : hello_client.o
	gcc hello_client.o -o client

server : hello_server.o
	gcc hello_server.o -o server

hello_client.o : hello_client.c
	gcc -W -Wall -c hello_client.c

hello_server.o : hello_server.c
	gcc -W -Wall -c hello_server.c
