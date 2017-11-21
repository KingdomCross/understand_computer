/*
 *Usage:
 *
 * gcc -DCOMPILETIME -c mymalloc.c 
 * gcc -I. -o intc int.c mymalloc.c
 *
 * ./intc
 *
 */

#ifdef COMPILETIME
#define<stdio.h>
#include<malloc.h>


/* malloc wrapper function */
void *mymalloc(size_t size)
{
	void *ptr = malloc(size);
	printf("malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}

/* free wraper function */
void myfree(void *ptr)
{
	free(ptr);
	printf("free(%p)\n", ptr);
}

#endif //endif COMPILETIME


/*
 * Usage:
 *
 * gcc -DLINKTIME -c mymalloc.c 
 * gcc -c int.c
 * gcc -Wl,--wrap,malloc -Wl,--wrap,free -o intl int.o mymalloc.o
 *
 * ./intl
 *
 */
#ifdef LINKTIME
#include<stdio.h>


void *__real_malloc(size_t size);
void __real_free(void *ptr);


/* malloc wraper function */
void *__wrap_malloc(size_t size)
{
	void *ptr = __real_malloc(size); /* Call libc malloc */
	printf("malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}

/* free wraper function */
void __wrap_free(ptr)
{
	__real_free(ptr); /* Call libc free */
	printf("free(%p)\n", ptr);
}

#endif //endif LINKTIME


/*
 *Usage : the program has some problem, but I can't find it.
 *
 *> gcc RUNTIME -shared -fpic -o mymalloc.so mymalloc.c -ldl
 *> gcc -o intr int.c
 *
 *> LD_PRELOAD="./mymalloc.so" ./intr
 * malloc(32) = 0x1bf7010
 * free(0x1bf7010)
 */

#ifdef RUNTIME
#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

/* malloc wrapper function */
void *malloc(size_t size)
{
	void *(*mallocp)(size_t size);
	char *error;

	mallocp = dlsym(RTLD_NEXT, "malloc"); /* Get address of libc malloc */
	if((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	char *ptr = mallocp(size); /* Call libc malloc */
	printf("malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}

/* free wrapper function */
void free(void *ptr)
{
	void (*freep)(void *) = NULL;
	char *error;

	if(!ptr)
		return;

	freep = dlsym(RTLD_NEXT, "free"); /* Get address of libc free */
	if((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}
	freep(ptr); /* Call libc free */
	printf("free(%p)\n", ptr);
}

#endif //endif RUNTIME
