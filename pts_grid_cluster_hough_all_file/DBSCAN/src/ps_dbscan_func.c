#include"ps_dbscan.h"

// initialization   
void ps_init()  
{  
	data_size = 1200;
	point = (ps_point_t*)malloc(sizeof(struct ps_point) * (data_size + 1));  
    if( !point )  
    {  
    	printf("point malloc error\n");  
        exit(0);  
    }  
    for(int i= 0; i < data_size;i++)
    {
    	point[i].x = 0;
    	point[i].y = 0;
    	point[i].r = 0;
    	//printf("%d\t", i);
    }
    
    core_object_collection = (ps_core_object_t*)malloc(sizeof(struct ps_core_object) * (data_size + 1));  
    if( !core_object_collection )  
    {  
        printf("core object collection malloc error!\n");  
        exit(0);  
    }  
    
    int core_object_index;         //traverse  
    for( core_object_index = 1; core_object_index <= data_size; core_object_index++ )  
    {  
        core_object_collection[core_object_index].core_object_ID = 0;             //if the value equal 0 denote it's not core object  
        core_object_collection[core_object_index].reachable_size = 0;            //INITIALASSIGN_DIRECTLYDENSITYREACHABLE  
        core_object_collection[core_object_index].capacity = INITIAL_ASSIGN_DIRECTLY_DENSITY_REACHABLE;  
        core_object_collection[core_object_index].directly_density_reachable = (int*)malloc(sizeof(int) * (INITIAL_ASSIGN_DIRECTLY_DENSITY_REACHABLE + 1));  
        if( !core_object_collection[core_object_index].directly_density_reachable )  
        {  
            printf("core object collection malloc error: %d\n", core_object_index);  
            exit(0);  
         }  
    }  
      
}  
void ps_free()
{
	free(point);
	free(core_object_collection);
	int core_object_index;         //traverse  
    for( core_object_index = 1; core_object_index <= data_size; core_object_index++ )  
    {  
        
        free(core_object_collection[core_object_index].directly_density_reachable);
        
    }  
     free(core_object);
   
}   
      
// read data from file; set the value of point 
void ps_read_data(char OPEN_PATH[])  
{  
   FILE* fread; 
	
   if( NULL == (fread = fopen(OPEN_PATH, "r")))  
   {  
       printf("open file(%s) error!\n", OPEN_PATH);  
       exit(0);  
   }
     
   int i;  
   printf("%s\n", OPEN_PATH);
   double x, y, r;
   fseek(fread, 0L, SEEK_SET);
   for( i = 1; !feof(fread); i++ )  
   {  
   		int scn = fscanf(fread, "%lf\t%lf\t%lf\n", &x, &y, &r);
		if( scn != 3)  
        {  
        	printf("scanf error: %d\t%d\n", i, scn);  
            exit(0);  
        } 
        else
        {
        	point[i].x = x;
    		point[i].y = y;
    		point[i].r = r; 
    		//printf("%lf\t%lf\t%lf\n", point[i].x, point[i].y, point[i].r);
    	}
        
   } 
   data_size = i-1;
   //printf("data_size = %d\n", data_size);
   fclose(fread); 
}  
      
// calculate distance between two point 
double ps_calculate_distance_two_points(int first_point, int second_point)  
{     
	double temp = sqrt( pow((double)(point[first_point].x - point[second_point].x), 2) + 
						pow((double)(point[first_point].y - point[second_point].y), 2)
					  ); 
	// printf("%f\n", temp); 
	return temp;  
}  
     
      
// calculate distance bewteen specifed point to all others points 
// and seek the directly_density_reachable of the specified point &pointID 
void ps_calculate_distance_one2all(int pointID)  
{  
	//printf("calculate_distance_ one2all data_size = %d", data_size);
	int i;  
	for( i = 1; i <= data_size; i++ )  
	{  
		if( i != pointID )  
		{  
			if( ps_calculate_distance_two_points(pointID, i) <= neighborhood )  
			{  
				core_object_collection[pointID].reachable_size++;  
				if( core_object_collection[pointID].reachable_size > core_object_collection[pointID].capacity )  
				{  
					printf("\nrealloc\n\n"); 
					 
					core_object_collection[pointID].directly_density_reachable = 
						(int*)realloc(core_object_collection[pointID].directly_density_reachable, sizeof(int) * 
						(core_object_collection[pointID].capacity + INCREASEMENT_DIRECTLY_DENSITY_REACHABLE)); 
						 
					if( !core_object_collection[pointID].directly_density_reachable )  
					{  
						printf("core_object_collection[%d].directly_density_reachable realloc error\n", i);  
						exit(0);  
					}  
					core_object_collection[pointID].capacity += INCREASEMENT_DIRECTLY_DENSITY_REACHABLE;  
				}  
				core_object_collection[pointID].directly_density_reachable[core_object_collection[pointID].reachable_size] = i;  
			}  
		}  
	}  
}  


     
// calculate distance between all points 
void ps_calculate_distance_all()  
{  
	int i;          //traverse all the data_size  
	//printf("calculate_distance_ add data_size = %d", data_size);
	for( i = 1; i <= data_size; i++ )  
	{  
		ps_calculate_distance_one2all(i);  
	}  
}  
      
// specify the core object by statisticing the number of directly_density_reachable for all points 
// the value of coreObject in the struct of coreObject_Collection be used to denote whether or not a core object 

void ps_statistic_core_object()  
{  
	//printf("statistic_core_object data_size = %d\n", data_size);
	//printf("\n\n\n\nstatistic_core_object size_of_core_object = %d\n\n\n\n", size_of_core_object);
	size_of_core_object = 0;
	int i;  
	for( i = 1; i <= data_size; i++ )  
	{  
		if( core_object_collection[i].reachable_size >= MinPts - 1 )           //core object  
		{  
				size_of_core_object++;  
				core_object_collection[i].core_object_ID = i;          //ueing non_zero value to denote this point is a core_object
				//printf("core_object_ID = %d\n", i);  
		}  
	}  
	//printf("statistic_core_object size_of_core_object = %d\n", size_of_core_object);
}  
      
// show the struct of the directly_density_reachable of all coreObject 
void ps_show_information()  
{  
	int direct_reachable;  
	int core_object_index;  
	//printf("ps_show_information data_size = %d", data_size);
	for( core_object_index = 1; core_object_index <= data_size ; core_object_index++ )  
	{  
		printf("%d---", core_object_collection[core_object_index].core_object_ID);  
		for( direct_reachable = 1; 
			 direct_reachable <= core_object_collection[core_object_index].reachable_size; 
			 direct_reachable++
			 )  
		{  
			printf("%d ", core_object_collection[core_object_index].directly_density_reachable[direct_reachable]);  
		}  
		printf("\n");  
	}  
}  
      
// set the struct of @coreObject in term of the result of coreObject_Collection 
void ps_set_core_object()  
{  
	//printf("ps_set_core_object data_size = %d", data_size);
	//printf("ps_set_core_object size_of_core_object = %d\n", size_of_core_object);
	core_object = (ps_core_object_t*)malloc(sizeof(struct ps_core_object) * (size_of_core_object + 1));  
	if( !core_object )  
	{  
		printf("core_object malloc error!\n");  
		exit(0);  
	} 
	 
	int i;  
	int j;  
	int count = 1; 
	 
	for( i = 1; i <= data_size; i++ )  
	{  
		if( core_object_collection[i].reachable_size >= MinPts - 1 )  
		{  
			core_object[count].core_object_ID = i;  
			core_object[count].directly_density_reachable = (int*)malloc(sizeof(int) * (core_object_collection[i].reachable_size + 1));  
			
			
			if( !core_object[count].directly_density_reachable )  
			{  
				printf("coreObject[%d].directly_density_reachable malloc error!\n");  
				exit(0);  
			} 
			 
			for( j = 1; j <= core_object_collection[i].reachable_size; j++ )  
			{  
				core_object[count].directly_density_reachable[j] = core_object_collection[i].directly_density_reachable[j];  
			}  
			core_object[count].capacity = 0;     //change its function to flag whether this core object has beed selected  
			core_object[count].reachable_size = core_object_collection[i].reachable_size;  
			count++;  
		}  
	}  
}  




// some preparatory for the algorithem DBSCAN 
// create the set of Un-accessed data 

int* ps_preparatory_DBSCAN()  
{  
	//printf("ps_preparatory_DBSCAN data_size = %d", data_size);
	//initial the Un-accessed data  
	int* unaccessed_data;  
	unaccessed_data = (int*)malloc(sizeof(int) * (data_size + 1));  
	if( !unaccessed_data )  
	{  
		printf("unaccessed_data malloc error!\n");  
		exit(0);  
	}  
	int i;  
	for( i = 0; i <= data_size; i++ )  
		unaccessed_data[i] = 0;          //0 denote haven't been visited  
	//seek the noise  
	for( i = 1; i <= data_size; i++ )  
	{  
		if( 0 == core_object_collection[i].reachable_size )  
		{  
			unaccessed_data[i] = -1;     //uses non-zero to denote the noise  
		}  
	}  
      
	return unaccessed_data;  
}  
    
/******************************************************************************************************************** 
******************************************************************************************************************** 
* 
*                          DBSCAN 
* 
******************************************************************************************************************** 
********************************************************************************************************************/ 

 
void ps_DBSCAN(char OUT_PATH[])  
{  
	//printf("ps_DBSCAN data_size = %d", data_size);
	int* un_accessed_data = ps_preparatory_DBSCAN();  
	int* old_unaccessed_data;                                //save the original information of un_accessed_data  
	int i;  
	old_unaccessed_data = (int*)malloc(sizeof(int) * (data_size + 1));  
	if( !old_unaccessed_data )  
	{  
		printf("old_unaccessed_data malloc error!\n");  
		exit(0);  
	}  
	for( i = 1; i <= data_size; i++ )  
		old_unaccessed_data[i] = un_accessed_data[i];  
      
	//initial the queue for containing the directly_density_reachable  
	link_queue_t work_queue;  
	ps_initial_queue(&work_queue);  
      
	int cluster_count = 0;  
	int random_core_object_ID;  
	int pop_queue_ID = 0;  
	int test_counter_1 = 1;
	int test_counter_2 = 1;  
      
	while( ps_exist_core_object() != 0 )                             //still exist core object in the @coreObject  
	{  
		printf("\n---------%d\n", test_counter_1);  
		ps_refresh_old_unaccessed_set(un_accessed_data, old_unaccessed_data);  
		random_core_object_ID = ps_get_random_core_object();  
		ps_add2queue_base_core_object(&work_queue, random_core_object_ID);  
		ps_update_unaccess_set(un_accessed_data, random_core_object_ID);  
		test_counter_2 = 1;  
		while( !ps_is_empty_queue(work_queue) )  
		{  
			printf("\n\t++++++++++++%d\n", test_counter_2++);  
			ps_delete_queue(&work_queue, &pop_queue_ID);  
			if( core_object_collection[pop_queue_ID].reachable_size >= MinPts - 1 )  
			{  
				ps_add2queue_intersection_based(&work_queue, un_accessed_data, pop_queue_ID);  
			}  
		}  
		cluster_count += 1;  
		printf("\ncluster_count is %d\n", cluster_count);  
		ps_get_cluster(un_accessed_data, old_unaccessed_data, cluster_count, OUT_PATH);  
		ps_update_core_object(un_accessed_data);  
		test_counter_1++; 
		if(test_counter_1 > 100)
		 	break;
	}  
	// ps_save_noise(un_accessed_data, OUT_PATH);  
}  
      
      
/* 
 * the purpose of this function is to judeg whether or not exist core_object in the @coreObject 
 *  the component in the struct of coreObject is to determin the existence of the corresponding core object  
 *      return 0: non-exist 
 *      return 1: exist 
 * 
 */  
int ps_exist_core_object()  
{  
	int core;  
	//printf("ps_set_core_object size_of_core_object = %d\n", size_of_core_object);
	for( core = 1; core <= size_of_core_object; core++ )  
	{  
		if( 0 == core_object[core].capacity )  
		{  
			return 1;  
		}  
	} 
	 
	return 0; 
	 
}  


//
void ps_refresh_old_unaccessed_set(int* un_accessed_data, int* old_unaccessed_data)  
{  
	int i;  
	for( i = 1; i <= data_size; i++ )  
	{  
		old_unaccessed_data[i] = un_accessed_data[i];  
	}  
}  


/* 
 * select a core_object randomly 
 *  the retuen value is the ID of selected core_object 
 * 
 */  
int ps_get_random_core_object()  
{  
	//select a core object randomly, and insert the directly_density_reachable of it into to queue.  
	int i, j;  
	int core_object_count = 0;  
	for( i = 1; i <= size_of_core_object; i++ )  
	{  
		if( core_object[i].capacity == 0 )  
			core_object_count += 1;  
	}  
	int* auxiliary_array;  
	auxiliary_array = (int*)malloc(sizeof(int) * (core_object_count + 1));  
	if( !auxiliary_array )  
	{  
		printf("auxiliary_array malloc error!\n");  
		exit(0);  
	}  
          
	int counter_au = 1;  
	for( i = 1; i <= size_of_core_object; i++ )  
	{  
		if( core_object[i].capacity == 0 )       //still have not been selected  
		{  
			auxiliary_array[counter_au++] = core_object[i].core_object_ID;  
		}  
	}  
	int random_core_object_ID;  
	int random_index;  
	int length = core_object_count;  
	random_index = rand() % length + 1;  
	random_core_object_ID = auxiliary_array[random_index];  
	auxiliary_array[random_index] = auxiliary_array[length--];  
	
	return random_core_object_ID;  
} 

 
/* 
 * after selected a random core_object, we need to add the directly_density_reachable of this core object to the queue 
 *  particular note: instead use the coreObject, we need to use the original struct coreObject_Collection, 
 *           because of the incomplete in the index of @coreObject. 
 * 
 * 
 */  
void ps_add2queue_base_core_object(link_queue_t* LQ, int core_object_ID)  
{  
	int i;  
	for( i = 1; i <= core_object_collection[core_object_ID].reachable_size; i++ )  
	{  
		ps_insert_queue(LQ, core_object_collection[core_object_ID].directly_density_reachable[i]);  
	}  
	
}  


/* 
 * after selected a random core_object. we need to update the information about un-accessed-set 
 *  particular note: instead use the coreObject, we need to use the original struct coreObject_Collection, 
 *           because of the incomplete in the index of @coreObject. 
 * 
 */  
void ps_update_unaccess_set(int* un_accessed_data, int random_core_object_ID)  
{  
	int i;  
	for( i = 1; i <= core_object_collection[random_core_object_ID].reachable_size; i++ )  
	{  
		un_accessed_data[core_object_collection[random_core_object_ID].directly_density_reachable[i]] = 
            			core_object_collection[random_core_object_ID].directly_density_reachable[i];  
	}  
	un_accessed_data[random_core_object_ID] = random_core_object_ID;      //core object has visited  
        
}  


/* 
 * if exist the core_object in the list of directly_density_reachable of other core_object 
 * add the element in the @workqueue which is not even dealed with of the core_object 
 * and update the @un_accessed_set. 
 * 
 */  
void ps_add2queue_intersection_based(link_queue_t* LQ, int* un_accessed_set, int pop_queue_ID)  
{  
	int core_DDR;           //trverse the core_directly_reachable of pop_queue_ID  
	for( core_DDR = 1; core_DDR <= core_object_collection[pop_queue_ID].reachable_size; core_DDR++ )  
	{  
		if( 0 == un_accessed_set[core_object_collection[pop_queue_ID].directly_density_reachable[core_DDR]] )  
		{  
			ps_insert_queue(LQ, core_object_collection[pop_queue_ID].directly_density_reachable[core_DDR]); 
			 
			un_accessed_set[core_object_collection[pop_queue_ID].directly_density_reachable[core_DDR]] = 
				core_object_collection[pop_queue_ID].directly_density_reachable[core_DDR];  
		}  
	}  
}  



/* 
 * get cluster based on a core object 
 * 
 */  
void ps_get_cluster(int* un_accessed_data, int* old_unaccessed_data, int cluster_ID, char OUT_PATH[])  
{  
	char file_name[200];  
	sprintf(file_name, "%s/cluster_%d.txt",OUT_PATH, cluster_ID);  
	FILE* fwrite;  
	
	if( NULL == (fwrite = fopen(file_name, "w")))  
	{  
		printf("open file(%s) error\n", file_name);  
		exit(0);  
	}  
	printf(" DBSCAN ");
	int i;  
	for( i = 1; i <= data_size; i++ )  
	{  
		if( un_accessed_data[i] != old_unaccessed_data[i] )  
		{  
			fprintf(fwrite, "%f\t%f\n", point[i].x, point[i].y);  
		}  
	} 
	 
	fclose(fwrite);  
}  



//
void ps_update_core_object(int* un_accessed_data)  
{  
	int i;  
	for( i = 1; i <= size_of_core_object; i++ )  
	{  
		if( 0 != un_accessed_data[core_object[i].core_object_ID] )  
		{  
			core_object[i].capacity = 1;         //denote this core object has been dealed  
		}  
	} 
	 
}  



void ps_save_noise(int* un_accessed_data, char OUT_PATH[])  
{  
	FILE* fwrite_noise;  
	char file_name[200];  
	sprintf(file_name, "%snoise.txt",OUT_PATH);  
	if( NULL == (fwrite_noise = fopen(file_name, "w")))  
	{  
		printf("open file(nosie.data) error!\n");  
		exit(0);  
	}  
	
	int i;  
	printf("\nshow the noise data:\n");  
	for( i = 1; i <= data_size; i++ )  
	{  
		if( un_accessed_data[i] == -1 || un_accessed_data[i] == 0 )  
		{  
			fprintf(fwrite_noise, "%f\t%f\n", point[i].x, point[i].y);  
			printf("%f\t%f\n", point[i].x, point[i].y);  
		}  
	} 
	
	fclose(fwrite);
	 
}  
    
