#ifndef PS_DBSCAN_H_
#define PS_DBSCAN_H_
    
#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  
#include<time.h>  
#include<string.h>  

#include"ps_queue.h"      
#include"ps_type.h"



//#define INITIALASSIGN_COREOBJECT      100  
//#define INCREASEMENT_COREOBJECT       100       
#define INITIAL_ASSIGN_DIRECTLY_DENSITY_REACHABLE  7000  
#define INCREASEMENT_DIRECTLY_DENSITY_REACHABLE   10000  


static double neighborhood = 0.2;  
static int MinPts = 3;  
static char file_name[200] = "../TEST_data/C0.400000";  
static int data_size = 7641;  
 
static int size_of_core_object;  
static ps_point_t* point;  
static ps_core_object_t* core_object_collection;  //collectint the core_object  
static ps_core_object_t* core_object;         

      
void	ps_init();  
void	ps_read_data();  
double	ps_calculate_distance_two_points(int, int);  
void	ps_calculate_distance_one2all(int);  
void 	ps_calculate_distance_all();  
void 	ps_statistic_core_object();  
void 	ps_show_information();  
void 	ps_set_core_object();  
int* 	ps_preparatory_DBSCAN();  
void 	ps_DBSCAN();  
void 	ps_refresh_old_unaccessed_set(int*, int*);  
int 	ps_exist_core_object();  
int 	ps_get_random_core_object();  
void 	ps_add2queue_base_core_object(link_queue_t*, int);  
void 	ps_update_unaccess_set(int*, int);  
void 	ps_add2queue_intersection_based(link_queue_t*, int*, int);  
void 	ps_get_cluster(int*, int*, int);  
void 	ps_update_core_object(int*);  
void 	ps_save_noise(int*);  

 

#endif
      
  
