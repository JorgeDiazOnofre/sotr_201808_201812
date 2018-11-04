#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
char c='A';

int main()
{
	printf("c=%c\n",c);
	pid_t pid=fork();
	if (pid){/* padre */
		printf("PROCESO PADRE con identificador %d\n",getpid());
		printf("c=%c\n",c);
		c='B';
		sleep(5);
		printf("PADRE: c=%c\n",c);
		sleep(5);
	}else{/* hijo */
		printf("PrOCESO HIJO con identificador %d\n",getpid());
		printf("CON PROCESO PADRE 	%d\n",getppid());
		printf("HIJO c=%c\n",c);
		sleep(6);
		printf("HIO c=%c\n",c);

	}
	return 0;
}
