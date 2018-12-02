#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>

int main(int argc,char *argv[])
{
	pid_t pid;
	int intA;
	if((pid=fork())==0){/*hijo*/	
			printf("teclea un entero: ");
			scanf("%d",&intA);
			return intA;
			}
			else{/*padre*/
				waitpid(pid,&intA,WUNTRACED|WCONTINUED);
				if(WIFEXITED(intA)){
					printf("intA=%d\n",intA=WEXITSTATUS(intA));
					printf("Ud tecleo un ");
				if(intA%2)
					printf("impar.\n");
					else
					printf("par.\n");
					}else{
						printf("WIFEXITED(intA) devolvio false!!!!\n");
						}
						}
	return 0;					
}
