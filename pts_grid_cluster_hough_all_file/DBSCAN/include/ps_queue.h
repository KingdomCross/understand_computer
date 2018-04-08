#ifndef PS_QUEUE_H_
#define PS_QUEUE_H_

#include<stdio.h>  
#include<stdlib.h> 
#include<math.h>


typedef struct queue_node  
{  
	int data;  
	struct queue_node* next;  
	
}queue_node_t, *queue_node_ptr; 

 
typedef struct link_queue  
{  
	queue_node_ptr front;  
	queue_node_ptr rear;  
	
}link_queue_t;  

      
void ps_initial_queue(link_queue_t*);  
void ps_insert_queue(link_queue_t*, int);  
void ps_delete_queue(link_queue_t*, int*);  
void ps_print_queue(link_queue_t);  
void ps_test_queue();  
int  ps_is_empty_queue(link_queue_t);  


#endif

