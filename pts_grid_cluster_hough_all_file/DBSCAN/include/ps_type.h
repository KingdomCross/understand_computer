#ifndef PS_TYPE_H_
#define PS_TYPE_H_


typedef struct ps_point  
{  
	double x;  
	double y; 
	double r; 
}ps_point_t;  

typedef struct ps_core_object  
{  
	int  core_object_ID;  
	int* directly_density_reachable;  //store the directly density_reachable point of corePointID  
	int  reachable_size;      //the number of directly density reachable  
	int  capacity;           //the current capacity of the dynamic array @directlyDensityReachable  
}ps_core_object_t;  




#endif
