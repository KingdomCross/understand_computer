#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	int status;
	pid_t pid;
	
	//
	if((pid = fork()) < 0) 
	{
		printf("fork error\n");
		exit(1);
	}
	else if(pid == 0)  // child
	{
		exit(7);
	}
	
	if(wait(&status) != pid) // wait for child
	{
		printf("wait error\n");
		exit(1);
	}
	pre_exit(status);  // and print its status
	
	//
	if((pid = fork()) < 0)  
	{
		printf("fork error\n");
		exit(1);
	}
	else if(pid == 0)	// child
	{
		abort();		// generates SIGABRT
	}
	
	if(wait(&status) != pid)	// wait for child
	{
		printf("wait error\n");
		exit(1);
	}
	pre_exit(status);	 // and print its status
		
	//
	if((pid = fork()) < 0)  
	{
		printf("fork error\n");
		exit(1);
	}
	else if(pid == 0)	// child
	{
		status /= 0;		// generates SIGABRT
	}
	
	if(wait(&status) != pid)	// wait for child
	{
		printf("wait error\n");
		exit(1);
	}
	pre_exit(status);	 // and print its status	
	
	exit(0);
}

