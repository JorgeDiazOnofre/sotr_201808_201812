#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#define MAXLINE 100


#define STDOUT_FILENO 1
void err_sys(const char *,...)__attribute__((noreturn));
int main()
{
	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];

	if (pipe(fd)<0)
		err_sys("pipe error");
	if ((pid=fork())<0){
		err_sys("fork error");
	} else if (pid>0){	/* parent */
		close(fd[0]);
		write(fd[1],"hello world\n",12);
	} else {
		close(fd[1]);
		n=read(fd[0],line,MAXLINE);
		write(STDOUT_FILENO,line,n);
	}
	exit(0);
}

void err_sys(const char *fmt,...){
	perror(fmt);
	exit(1);
}
