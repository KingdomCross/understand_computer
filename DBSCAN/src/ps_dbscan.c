#include"ps_queue.h"
#include"ps_dbscan.h"

int main(int argc, char* argv[])  
{
	// ps_test_queue();  
	
	ps_init();  
	ps_read_data();
	ps_calculate_distance_all();
	ps_statistic_core_object();  
	// ps_show_information();  
	ps_set_core_object(); 
	ps_DBSCAN();  
	
	return 0;  
	
}  
