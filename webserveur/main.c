#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "socket.h"


int main(void){

  int socket_serveur=creer_serveur(8080);

  while(1){
     int socket_client ;
     socket_client = accept(socket_serveur, NULL,NULL);
     if(socket_client == -1){
       perror("accept");
       printf("accept");
       return -1;
     }
 const char *message_bienvenue = "*** Salut les  lapins ! *** \nBienvenue sur le serveur vachement interessant de la region Est qui remue les synapses et reveille les zygomatiques en hibernation. \nAnticyclone garanti.\n"  ;
 char* buffer = char[1024] ;
 int i;
 for(i = 0;i<10;i++){

   int nb = read(socket_client, buffer, sizeof(char)*1024);
   while((buffer =readd)
 write(socket_client, message_bienvenue, strlen(message_bienvenue));
 sleep(1);
 }
  }
  return 0;
}
