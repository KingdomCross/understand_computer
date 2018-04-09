#include <stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	pid_t child = fork();

	if( child == -1 ) 
	{ 
		printf("\nfork child error.");
		exit(0);
	} 
	else if(child == 0)
	{

		if ((child = fork()) < 0)
		{
			printf("fork error\n");
			exit(1);
		}
		else if (child > 0)
		{
			exit(0);
		}
		
		sleep(2);
		printf("second child,parent pid %d\n",getppid());
		exit(0);
	}
	
    
	if (waitpid(child,NULL,0) != child)
	{
		printf("waitpid error\n");
		exit(1);
	}
		
		
	sleep(10);
	exit(0);


}
