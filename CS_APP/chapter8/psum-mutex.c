#include"csapp.h"

#define MAXTHREADS 32

void *sum_mutex(void *vargp); // thread routines

// global shared variables

long gsum = 0; // global sum
long nelems_per_thread; // number of elements to sum
sem_t mutex; // mutex to protect global sum 

int main(int argc, char **argv)
{	
	long i, nelems, log_nelems, nthreads, myid[MAXTHREADS];
	pthread_t tid[MAXTHREADS];
	
	// get input arguments
	if(argc != 3) {
		printf("Usage: %s <nthreads> <log_nelems>\n", argv[0]);
		exit(0);
	}
	
	printf("threads should be power(2, n), now\n");
	printf("threads = %s\n", argv[1]);
	printf("log_nelems = %s\n\n", argv[2]);
	
	nthreads = atoi(argv[1]);
	log_nelems = atoi(argv[2]);
	nelems = (1L << log_nelems);
	nelems_per_thread = nelems / nthreads;
	sem_init(&mutex, 0, 1);
	
	// create peer threads and wait for them to finish
	for(i = 0; i < nthreads; i++) {
		myid[i] = i;
		Pthread_create(&tid[i], NULL, sum_mutex, &myid[i]);
	}
	
	for (i = 0; i< nthreads; i++) {
		Pthread_join(tid[i], NULL);
	}
	
	// check final answer
	if(gsum != (nelems * (nelems -1))/2) {
		printf("Error: result = %ld\n", gsum);
	} else {
		printf("Result = %ld\n", gsum);
	}
	
	exit(0);
}

// thread routine for psum-mutex.c
void *sum_mutex(void *vargp)
{
	long myid = *((long*)vargp); // extract the thread ID
	long start = myid * nelems_per_thread; // start element index
	long end = start + nelems_per_thread; // end element index
	long i;
	
	for(i = start; i < end; i++) {
		P(&mutex);
		gsum += i;
		V(&mutex);
	}
	
	return NULL;
}
