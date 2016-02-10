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
	int socket_client ;
	char buffer[1024] ="";

	while(1){
		
		socket_client= accepte_client(socket_serveur);
		
		if(fork()!=0){
		int i = read(socket_client, buffer, sizeof(char)*1024);
		
		
		while(strcmp("fin\n",buffer)!=0){	
			if( write(socket_client,buffer,i)==-1){
				perror("write");
			}
			if((i=read(socket_client,buffer,sizeof(char)*1024))==-1){
	  			perror("read");
			}
		}
			
		}
close(socket_client);
		
	}
		
	
	return 0;
}
