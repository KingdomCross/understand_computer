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
	
	printf("before vfork\n");
	
	if((pid = vfork()) < 0)
	{
		printf("vfork_error\n");
		exit(2);
	}
	else if(pid == 0)
	{
		globalvar++;
		var++;
		printf("in child process"); // 注意此处有无换行符的区别
		_exit(0); // 结束子进程， 注意此处_exit, _Exit, exit的区别
	}
	else
	{
		sleep(2);
	}
	// 父进程继续从此处执行
	printf("parents process: pid = %ld, glob = %d, var = %d\n", (long)getpid(), globalvar, var);
	
	exit(0);
}

