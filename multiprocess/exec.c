#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

char *env_init[] = { "USER=unknow", "PATH=/tmp", NULL};

int main()
{
	pid_t pid;
	
	if((pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execle("/home/dean/projects/understand_computer/multiprocess/echoall", 
		            "echoall", "myarg1", "MY ARG2", (char *)0, env_init) < 0 )
		{
			printf("execle error 1\n");
			exit(1);
		}
	}
		
	if ( waitpid(pid, NULL, 0) < 0)
	{
		printf("execle error 2\n");
		exit(1);
	}
		
	if((pid = fork()) < 0)
	{
		printf("execle error 3\n");
		exit(1);
	}
	else if( pid == 0)
	{
		if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0)
		{
			printf("execle error 4\n");
			exit(1);
		}
	}
	exit(0);
}

