#include"ps_queue.h"
  
// some operation about queue 


void ps_initial_queue(link_queue_t* LQ)  
{  
	LQ->front = (queue_node_ptr)malloc(sizeof(struct queue_node));  
	if( !LQ->front )  
	{  
		printf("Queue initial malloc error!");  
        exit(0);  
    } 
     
    LQ->rear = LQ->front;  
    LQ->rear->next = NULL;  
}  
    
    
void ps_insert_queue(link_queue_t* LQ, int pointID)  
{  
	queue_node_ptr new = (queue_node_ptr)malloc(sizeof(struct queue_node));  
    
    if( !new )  
    {  
		printf("insert queue malloc error %d\n", pointID);  
        exit(0);  
    }  
    
    new->data = pointID;  
    new->next = LQ->rear;  
    LQ->rear->next = new;  
    LQ->rear = new;  
}
    
    
      
void ps_delete_queue(link_queue_t* LQ, int* pointID)  
{  
	queue_node_ptr p = LQ->front->next;  
    *pointID = p->data;  
    LQ->front->next = p->next;  
    
    if( p == LQ->rear )  
    	LQ->rear = LQ->front;  
    	
    free(p);  
} 

 
void ps_print_queue(link_queue_t LQ)  
{  
    if( 1 == ps_is_empty_queue(LQ) )  
    {  
        printf("\nqueue is empty\n");  
        return;  
    } 
     
    LQ.front = LQ.front->next; 
     
    while( LQ.front != LQ.rear )  
    {  
        printf("%d ", LQ.front->data);  
        LQ.front = LQ.front->next;  
    }  
    
    printf("%d\n", LQ.front->data);  
    
}  



int ps_is_empty_queue(link_queue_t LQ)  
{  
    return LQ.front == LQ.rear ? 1 : 0;  
} 
 
    
//test  
void ps_test_queue()  
{  
    link_queue_t L;  
        
    ps_initial_queue(&L);  
    ps_insert_queue(&L, 1);  
    ps_insert_queue(&L, 2);  
    ps_insert_queue(&L, 3);  
    ps_insert_queue(&L, 4);  
    ps_insert_queue(&L, 5);  
    ps_print_queue(L);  
        
    int test;  
        
    ps_delete_queue(&L, &test);  
    ps_delete_queue(&L, &test);  
    ps_delete_queue(&L, &test);  
    ps_delete_queue(&L, &test);  
        
    printf("is empty = %d\n", ps_is_empty_queue(L)); 
         
    ps_delete_queue(&L, &test);  
    printf("is empty = %d\n", ps_is_empty_queue(L));  
        
    ps_print_queue(L);  
    
}  
