#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>

char buf[500000];

int main() {
	int ntowrite, nwrite;
	char *ptr;
	
	ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
	fprintf(stderr, "read %d bytes\n", ntowrite);
	
	sef_fl(STDOUT_FILENO, O_NONBLOCK); // set nonblocking
	
	ptr = buf;
	while(ntowrite > 0) {
		errno = 0;
		nwrite = write(STDOUT_FILENO, ptr, ntowrite); 
		fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);
		
		if(nwrite > 0) {
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}
	
	clr_fl(STDOUT_FILENO, O_NONBLOCK); // clear nonblocking
	
	exit(0);
}
