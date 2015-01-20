hello_sockets.exe : hello_client.o hello_server.o
	gcc hello_client.o hello_server.o -o hello_sockets.exe

hello_client.o : hello_client.c
	gcc -W -Wall -c hello_client.c

hello_server.o : hello_server.c
	gcc -W -Wall -c hello_server.c

clean :
	rm *.0 hello_sockets.exe 
