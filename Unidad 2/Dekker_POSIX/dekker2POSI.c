#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> /*sleep()*/

 void task1();/*Memory to be shared counter*/
 void task2();
 
 

 int g1=0;/*Number of iterations*/
 int g2=0;
 int want1=0;
 int want2=0;
 int turn=1;
 int N=0;
 int SALIR=0;

 int main(int argc,char *argv[])
{
	  pthread_t thrd1,thrd2;/*Identifiers*/
	    int ret;
	      
	      /*Crea el primer hilo*/
	      ret=pthread_create(&thrd1,NULL,(void*)task1,(void*)&g1);
	        if(ret){
			    perror("pthread_create: task1");
			        exit(EXIT_FAILURE);
				  }
		  /*Crea el segundo hilo*/
		  ret=pthread_create(&thrd2,NULL,(void*)task2,(void*)&g2);
		    if(ret){
			        perror("pthread_create: task2");
				    exit(EXIT_FAILURE);
				      }

		      pthread_join(thrd2,NULL);
		        pthread_join(thrd1,NULL);
			
			printf("Number of cycles:%d\n",N);

			 

			    exit(EXIT_SUCCESS);
}/* end main()*/

void task1()
{
	int i=0;

	  while(i<10){
		      printf("Proceso 1 NO en seccion critica\n");
		      i++;
		      if(N>5){
			      printf("Proceso 1 :%d\n",N);
			      for(;;){
				      if(N>10){
					      printf("Abandonamos el for infinito de p\n");
					      SALIR=1;
					      break;
				      }

			      }
		      }
		      if(SALIR){
			      printf("Salimos del ciclo while de 1");
			      break;
		      }
		          want1=1;
			  while(want2){
				  if(turn==2){
					  want1=0;
					  while(!(turn==1));
					  want1=1;
				  }
			  }
			  printf("Proceso 1 en seccion critica\n");
			  N=N+1;
			  turn=2;
			  want1=0;
			     
		   }
}

void task2()
{
	int i=0;
	  while(i<10){

		      printf("Proceso 2 NO en seccion critica\n");
		      i++;
		      want2=1;
		      while(want1){
			      if (turn==1){
				      want2=0;
				      while(!(turn==2));
				      want2=1;
			      }
		      }
		      printf("Proceso 2 en seccion critica\n");
		      N=N+1;
		      turn=1;
		      want2=0;
	 }
}





