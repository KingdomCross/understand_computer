#ifndef SUBF_H_
#define SUBF_H_

#include"csapp.h"

typedef struct {
	int *buf; // buffer array
	int n;	// maximum number of slots
	int front; // buf[(front + 1)%n] is first item
	int rear; // buf[rear%n] is last item
	sem_t mutex; // protects accesses to buf
	sem_t slots; // counts available slots
	sem_t items; // counts available items
} sbuf_t;

void sbuf_init(sbuf_t *sp, int n);
void sbuf_deinit(sbuf_t *sp);
void sbuf_insert(sbuf_t *sp, int item);
void sbuf_remove(sbuf_t *sp);

#endif
