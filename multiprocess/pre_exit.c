#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>


void pre_exit(int status)
{
	int var;
	pid_t pid;
	
	if(WIFEXITED(status))
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
		WCOREDUMP(status) ? " (core file generated)":"");
#else
		"");
#endif
	
	else if(WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
		
}

