#include"grid.h"
#include"list_file.h"



int main()
{
	char OPEN_PATH[512] = "../../data/points/003/";
	char OUT_PATH[512]  = "../../data/grid_filter/003/";
	
	
	files_list_t* re_files_list = list_files(OPEN_PATH);
	for (int i=0; i< re_files_list->files_number; i++)
	{
			
		// printf("%s\n", re_files_list->files_name[i]);
		FILE* fin;
		FILE* fout;
		
		sprintf(OPEN_PATH + 22, "%s", re_files_list->files_name[i]); 
		fin = fopen(OPEN_PATH,"r");
		if (fin == NULL)
		{
			printf("file %s open failed!\n", re_files_list->files_name[i]);
			return 1;
		}
		
		unpack_point_t *unpack_data = (struct _unpack_point*)malloc(sizeof(struct _unpack_point));
		unpack_data->length = 0;
		for(int i =  0; !feof(fin); i++)
		{
			fscanf(fin, "%f%f%f",
					&unpack_data->point[i].x,
					&unpack_data->point[i].y,
					&unpack_data->point[i].z
				);
		
			unpack_data->length++;	
		}
		unpack_data->length--;
		
		float coff_cut = COFF_CUT_OFF;
		
		point_grid_t* grid_cell[GRID_MAX][GRID_MAX];
		grid_cell_memory(grid_cell);
		grid_cell_init( grid_cell);
		grid_on( unpack_data, grid_cell );
		grid_filter_by_percent(grid_cell, coff_cut);	
		
				
		sprintf(OUT_PATH+27, "%s", re_files_list->files_name[i]); 	
		fout = fopen(OUT_PATH,"w");
		if (fout == NULL)
		{
			printf("file %s open failed!\n", OUT_PATH);
			return 1;
		}
		
		grid_cell_output(grid_cell, fout);
		grid_cell_memory_free(grid_cell);
		
		fclose(fout);
		fclose(fin);
		free(unpack_data);
    }
    
    free(re_files_list);
    
	
	return 0;
}

