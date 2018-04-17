#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/acct.h>
#include<sys/types.h>
#include<signal.h>

#include"err_sys.h"

int main()
{
	pid_t pid;
	
	if( (pid = fork()) < 0 )
		err_sys("fork error\n");
	else if( pid != 0)  // parent
	{
		sleep(2);
		exit(2);
	}
	
	if( (pid = fork()) < 0)
		err_sys("fork error\n");
	else if( pid != 0)
	{
		// first child
		sleep(4);
		abort(); // terminate with core dump
	}
	
	if( (pid = fork()) < 0)
		err_sys("fork error\n");
	else if(pid != 0)
	{
		execl("/bin/dd", "dd", "if=/etc/passwd", "of=/dev/null", NULL);
		exit(7); // shouldn't get here
	}
	
	if( (pid = fork()) < 0)
		err_sys("fork error\n");
	else if(pid != 0) // third child
	{
		sleep(8);
		exit(0);
	}
	
	sleep(6);  // fourth child
	kill(getpid(), SIGKILL); // terminate w/signal, no core dump
	exit(6); // shouldn't get here
	
}

