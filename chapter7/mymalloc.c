/* gcc -DLINKTIME -c mymalloc.c */

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

#endif

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

#endif

