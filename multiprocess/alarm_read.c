#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<signal.h>
#include"err_sys.h"

static void sig_alrm(int);

int main()
{
	
	int n;
	char line[100];
	if (signal(SIGUSR1, sig_alrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error\n");
	
	alarm(10);
	if ((n = read(STDIN_FILENO, line, 100)) < 0)
		err_sys("read error");
	alarm(0);
	

	write(STDOUT_FILENO, line, n);
	exit(0);
}


static void sig_alrm(int signo)
{
	// nothing to do, just return to interrupt the read		
}

