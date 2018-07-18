#include"ps_queue.h"
#include"ps_dbscan.h"
#include"list_file.h"
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char* argv[])  
{
	// ps_test_queue();  
	
	char OPEN_PATH[512] = "../../data/grid_filter/004/";
	char OUT_PATH[512]  = "../../data/cluster/004/";
	
	
	files_list_t* re_files_list = list_files(OPEN_PATH);
	for (int i=0; i< re_files_list->files_number; i++)
	{
				
		// printf("%s\n", re_files_list->files_name[i]);

		sprintf(OPEN_PATH + 27, "%s", re_files_list->files_name[i]); 
		sprintf(OUT_PATH + 23, "C00%d", i); 
		
		int re = mkdir(OUT_PATH, S_IRWXU);
		if (re != 0)
			return re;
		printf("%s\n", OUT_PATH);
			
			
		ps_init();  
		ps_read_data(OPEN_PATH);
		
		ps_calculate_distance_all();
		
		size_of_core_object = 0;
		
		ps_statistic_core_object();  
		ps_show_information();  
		ps_set_core_object(); 
		// printf("%s\n", OUT_PATH);
		ps_DBSCAN( OUT_PATH);  	
		ps_free();
		
	}
    
    free(re_files_list);
    
	
	
	
	
	
	
	
	return 0;  
	
}  
