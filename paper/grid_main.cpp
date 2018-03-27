#include"grid.h"
#include<string>

point_grid_t* grid_cell[GRID_MAX][GRID_MAX];
using namespace std;

int main()
{
	FILE* fin;
	
	
	fin = fopen("./source_data/P201803251443_2.txt","r");
	if (fin == NULL)
	{
		printf("file open failed!\n");
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
	
	
	/*
	for (int i =  0; i < unpack_data->length; i++)
	{
		fprintf(fout, "%lf\t%lf\t%lf\n",
					unpack_data->point[i].x,
					unpack_data->point[i].y,
					unpack_data->point[i].z
				);
	}
	*/
	float coff_cut = 0;
	while(coff_cut < 1)
	{
		grid_cell_memory(grid_cell);
		grid_cell_init( grid_cell);
		grid_on( unpack_data, grid_cell );
	
		grid_filter_by_percent(grid_cell, coff_cut);	
		
		int grid_max = GRID_MAX;
		std::string fname = std::to_string(coff_cut);
		fname = std::string("./filter_data/C-serial/N") + 
			    to_string(grid_max) + 
			    std::string("/C") + 
			    fname;
		
		
		FILE* fout;
		fout = fopen((char*)fname.c_str(),"w");
		if (fout == NULL)
		{
			printf("file open failed!\n");
			return 1;
		}
		
		grid_cell_output(grid_cell, fout);
		grid_cell_memory_free(grid_cell);
		fclose(fout);	
		
		coff_cut += 0.05;
	}	
	free(unpack_data);
	fclose(fin);
	
	return 0;
}

