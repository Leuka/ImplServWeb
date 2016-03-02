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
      FILE * fd=fdopen(socket_client,"w+");
      
      while(strcmp("fin\n",buffer)!=0){	

	if( fgets(buffer, sizeof(buffer), fd) == NULL){
	  break;
	}
	if((fprintf(fd, "<Pop Hip> %s", buffer)==-1)){
	  perror("read");
	  
	}

      }

    }
      close(socket_client);
      exit(0);
  }		
	
    
	
    return 0;
  }



  
