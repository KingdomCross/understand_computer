#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include"err_sys.h"

int main()
{
	int status;
	
	if (( status = system("date")) < 0)
		err_sys("system() error");
	
	pre_exit(status);
	
	if (( status = system("nosuchcommand")) < 0)
		err_sys("system() error");
		
	pre_exit(status);
	
	if ((status = system("who; exit 44")) < 0)
		err_sys("system() error");
		
	pre_exit(status);
	
	exit(0);
	
}
	
