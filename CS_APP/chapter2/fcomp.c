
#include<stdio.h>
#include<stdlib.h>

double recip(int denom)
{
	return 1.0/(double) denom;
}

void do_something()
{
	/*just like the name says*/
	
}

void test1(int denom)
{
	double r1, r2;
	int t1, t2;
	
	r1 = recip(denom); /* Stored in memory*/
	r2 = recip(denom); /* Stored in register*/
	
	t1 = r1 == r2; /* Compares register to memory*/
	do_something(); /* Forces register save to memory*/
	t2 = r1 == r2; /* Compares memory to memory*/

	printf("test1 t1:r1 %f %c = r2 %f\n", r1, t1? '=' : '!', r2);
	printf("test1 t2:r1 %f %c = r2 %f\n", r1, t2? '=' : '!', r2);
}

int main(int argc, char** argv)
{
	if(argc != 2)
		printf("Please input a parameter\n");
	else
		test1(atoi(argv[1]));
	
	
	return 0;
	
}
	
	
	
