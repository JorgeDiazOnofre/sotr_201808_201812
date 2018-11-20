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

			 

			    exit(EXIT_SUCCESS);
}/* end main()*/

void task1()
{
	sleep(1);
	  while(1){
		      printf("Proceso 1 NO en seccion critica\n");
		          want1=1;
			  while(want2){
				  if(turn==2){
					  want1=0;
					  while(!(turn==1));
					  want1=1;
				  }
			  }
			  printf("proceso 1 en seccion critica\n");
			  turn=2;
			  want1=0;
			     
		   }
}

void task2()
{
	sleep(1);
	  while(1){

		      printf("Proceso 2 NO en seccion critica\n");
		      want2=1;
		      while(want1){
			      if (turn==1){
				      want2=0;
				      while(!(turn==2));
				      want2=1;
			      }
		      }
		      printf("Proceso 2 en seccion critica\n");
		      turn=1;
		      want2=0;
	 }
}





