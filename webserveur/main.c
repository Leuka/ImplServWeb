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
  const char *msg400 = "HTTP/1.1 400 Bad Request\r\nConnection: close\r\nContent-Length: 17\r\n\r\n400 Bad Request\r\n";
  const char *msg200 = "HTTP/1.1 200 OK\r\nContent-Length: length\r\n";
  char *methode;
  char *ressources;
  /*char *url;*/	
  char *spl;

  const char * message_bienvenue = "*** Salut les  lapins ! *** \nBienvenue sur le serveur vachement interessant de la region Est qui remue les synapses et reveille les zygomatiques en hibernation. \nAnticyclone garanti.\n\n"  ;

  while( (socket_client= accepte_client(socket_serveur))!= -1 ){
    if(fork()==0){
      FILE * fd=fdopen(socket_client,"w+");
      fgets(buffer, sizeof(buffer),fd);

      methode = strtok(buffer, " ");
      /*url = */strtok(NULL, " ");
      ressources = strtok(NULL, " ");
      spl = strtok(NULL, " ");
      
	printf("%s\n",methode );
printf("%s\n",ressources );
fprintf(fd, "%s\n", message_bienvenue );


    if ((strcmp(methode,"GET")==0) && (ressources != NULL)&& (spl == NULL) ){
		if (((strstr(ressources,"HTTP/1.0")==0) || (strstr(ressources,"HTTP/1.1")==0))){
	//if (strcmp(url,"/")==0){
		  fprintf(fd, "%s\n", message_bienvenue );
		  fprintf(fd, "%s\n", msg200 );
		  fflush(fd);
		  fclose(fd);
	//}
		}
		else {
		  fprintf(fd,"%s\n",msg400);
		  fflush(fd);
		  fclose(fd);
		}
    }
    /*
      while(strcmp("fin\n",buffer)!=0){	
      if( fgets(buffer, sizeof(buffer), fd) == NULL){
      return -1;
      }
      if((printf( "%s", buffer)==-1)){
      perror("read");
      }
      }*/
    close(socket_client);
    exit(0);
  }
    
  close(socket_client);
} 
return 0;
}



  
