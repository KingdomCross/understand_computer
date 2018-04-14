#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	if(( pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	else if (pid == 0) // child
	{
		if (execl("/home/dean/projects/understand_computer/multiprocess/testinterp",
				  "testinterp", "myarg1", "MY ARG2", (char *)0) < 0)
		{
			printf("execl error\n");
			exit(1);
		}
		
	}
	
	if(waitpid(pid, NULL, 0) < 0) // parent
	{
		printf("waitpid error\n");
		exit(1);
	}
	
	exit(0);
}

