#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> /*sleep()*/

 void task1();/*Memory to be shared counter*/
 void task2();
 

 int g1=0;/*Number of iterations*/
 int g2=0;
 int turn;
 #define N 2
 int interested[N];
 int FALSE=0;
 int TRUE=1;
 int G=0;

 void enter_region(int process){
	 int other;
	other=1-process;
	interested[process]=TRUE;
	turn=process;
	while((turn==process)&&(interested[other]==TRUE));
 }	

void leave_region(int process)
{
	interested[process]=FALSE;
}
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
		printf("G=%d\n",G);
			 

			    exit(EXIT_SUCCESS);
}/* end main()*/

void task1()
{
	int i=0;
	  while(i<10){
		  i++;
		      printf("Proceso 1 NO en seccion critica\n");
		      enter_region(0);
		      printf("proceso 1 en seccion critica\n");
		      G=G+1;
		      leave_region(0);
			     
		   }
}

void task2()
{
	int i=0;
	  while(i<10){
		  i++;
		      printf("Proceso 2 NO en seccion critica\n");
		      enter_region(1);
		      printf("Proceso 2 en seccion critica\n");
		      G=G+1;
		      leave_region(1);
	 }
}





