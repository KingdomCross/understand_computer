#include<stdio.h>
#include<unistd.h>
#include"err_sys.h"

int main(int argc, char *argv[])
{
	int status;
	
	if(argc < 2)
		err_quit("command-line argument required");
	
	if (( status = system(argv[1])) < 0)
		err_sys("system() error");
	
	pre_exit(status);
	
	exit(0);
}

