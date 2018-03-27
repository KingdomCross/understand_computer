#include"point_num_with_C_N.h"

unpack_point_t *unpack_data = (struct _unpack_point*)malloc(sizeof(struct _unpack_point));
using namespace std;

int main()
{
	FILE* fin;
	FILE* fout;
	
	fout = fopen("./points_C_N.txt","w");
	if (fin == NULL)
	{
		printf("file open failed!\n");
		return 1;
	}
	
	int grid_max = 10;
	while( grid_max <= 200)
	{
		
		float coff_cut = 0;
		while(coff_cut < 1)
		{
		
			std::string fname = std::to_string(coff_cut);
			fname = std::string("./C-serial/N") + 
					to_string(grid_max) + 
					std::string("/C") + 
					fname;
				
			fin= fopen((char*)fname.c_str(),"r");
	
			if (fout == NULL)
			{
				printf("file open failed!\n");
				return 1;
			}
		
		
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
			fprintf(fout,"%f\t%d\t%ld\n", coff_cut, grid_max,unpack_data->length);
		
			fclose(fin);	
		
			coff_cut += 0.05;
		}
		grid_max += 10;
	}
	
		
	free(unpack_data);
	fclose(fout);
	
	return 0;
}

