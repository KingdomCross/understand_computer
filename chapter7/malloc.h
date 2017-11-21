#define malloc(size) mymalloc(size)
#define free(ptr) my free(ptr)

void *mymalloc(size_t size);
void myfree(void *ptr);

