#include"err_sys.h"

void err_sys(const char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void err_quit(const	char* msg)
{
	printf("%s\n", msg);
	exit(0);
}
