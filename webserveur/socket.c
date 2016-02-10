#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "socket.h"

int creer_serveur(int port){
  
  int socket_serveur;
  socket_serveur = socket(AF_INET, SOCK_STREAM, 0);
  if(socket_serveur == -1){
    perror("socket_serveur");
  return -1;
  }

 
  struct sockaddr_in saddr;
  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(port) ;
  saddr.sin_addr.s_addr = INADDR_ANY ;

 if ( bind ( socket_serveur , ( struct sockaddr *)& saddr , sizeof ( saddr )) == -1){
   perror("bind socker_serveur");
   return -1;
 }

 if(listen(socket_serveur , 10) == -1){
   perror("listen socket_serveur");
   return -1;
 }
 
 return socket_serveur;
}

int accepte_client(int sock){
	int socket_client ;
    
	const char * message_bienvenue = "*** Salut les  lapins ! *** \nBienvenue sur le serveur vachement interessant de la region Est qui remue les synapses et reveille les zygomatiques en hibernation. \nAnticyclone garanti.\n"  ;


	socket_client = accept(sock, NULL,NULL);
    if(socket_client == -1){
       perror("accept");
       printf("accept");
       return -1;
	}

	write(socket_client, message_bienvenue, strlen(message_bienvenue));
    sleep(1);
	
	return socket_client;
}
