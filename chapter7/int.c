/*
 * gcc -DLINKTIME -c mymalloc.c
 * gcc -c int.c
 * gcc -W1,--wrap, malloc -W1,--wrap, free -o int1 int.o mymalloc.o
 */

#include<stdio.h>
#include<malloc.h>

int main()
{
	int *p = malloc(32);
	free(p);
	return 0;
}

