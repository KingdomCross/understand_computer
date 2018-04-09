#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

static void charatatime(char *);


int main()
{
	
	pid_t pid;
	
	pid = fork();
	if(pid < 0)
	{
		printf("fork_error\n");
		exit(2);
	}
	else if(pid == 0)
	{
		charatatime("output from child\n");
	}
	else 
	{
		charatatime("output from parent\n");
	}
	
	
	exit(0);
}

static void charatatime(char *str)
{
	char *ptr;
	int c;
	
	setbuf(stdout, NULL);  // 设置无缓冲标准输出
	for( ptr = str; (c = *ptr++) != 0;)
		putc(c, stdout);
}

