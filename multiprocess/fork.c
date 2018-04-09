#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int globalvar = 6;
char buf[] = "a write to stdout\n";


int main()
{
	int var;
	pid_t pid;
	
	var = 89;
	if ( write(STDOUT_FILENO, buf, sizeof(buf) -1) != sizeof(buf) -1)
	{
		printf("write error\n");
		exit(1);
	}
	
	printf("before fork\n");
	pid = fork();
	if(pid < 0)
	{
		printf("fork_error\n");
		exit(2);
	}
	else if(pid == 0)
	{
		printf("this is child process, pid is %d\n",getpid());
		globalvar++;
		var++;
	}
	else if(pid > 0)
	{
		printf("this is father process, pid is %d\n",getpid());
		sleep(2);
	}
	else
	{
		fprintf(stderr,"ERROR:fork() failed!\n");
	}
	
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globalvar, var);
	sleep(10);
	exit(0);
}

