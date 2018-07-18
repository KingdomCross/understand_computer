#include"grid.h"

void grid_cell_memory(point_grid_t* grid_cell[GRID_MAX][GRID_MAX])
{
	int row = 0, col = 0;
	for (row = 0; row < GRID_MAX; row++)
		for(col = 0; col < GRID_MAX; col++)
			grid_cell[row][col] = (struct _point_grid*)malloc(sizeof(struct _point_grid));

}

void grid_cell_init(point_grid_t* grid_cell[GRID_MAX][GRID_MAX])
{
	int row = 0, col = 0;
	for (row = 0; row < GRID_MAX; row++)
		for(col = 0; col < GRID_MAX; col++)
		{
			grid_cell[row][col]->length = 0UL;
			grid_cell[row][col]->max = Z_MIN;
			grid_cell[row][col]->min = Z_MAX;
			
		}
}


void grid_cell_memory_free(point_grid_t* grid_cell[GRID_MAX][GRID_MAX])
{
	int row = 0, col = 0;
	for (row = 0; row < GRID_MAX; row++)
		for(col = 0; col < GRID_MAX; col++)
			free(grid_cell[row][col]);
}

void grid_cell_output(point_grid_t* grid_cell[GRID_MAX][GRID_MAX], FILE *fp3)
{
	int row = 0, col = 0;
	for (row = 0; row < GRID_MAX; row++)
		for(col = 0; col < GRID_MAX; col++)
		{
			
			//fprintf(fp3, "%d\t%d\n", row, col);
			for (int k= 0; k < grid_cell[row][col]->length; k++)
				fprintf(fp3,"%.8f\t%.8f\t%.8f\n", grid_cell[row][col]->point3[k].x,
						      grid_cell[row][col]->point3[k].y,
						      grid_cell[row][col]->point3[k].z
						      );
			//fprintf(fp3, "\n\n");
		}
}


void grid_on(unpack_point_t* unpack_data, point_grid_t* grid_cell[GRID_MAX][GRID_MAX] )
{
	int i, j, row, col;
	for ( i=0, j=0; i < unpack_data->length; i++)
		if( unpack_data->point[i].x !=0 &&
		    unpack_data->point[i].y !=0 &&
		    unpack_data->point[i].z !=0 &&
		    unpack_data->point[i].x >= X_MIN &&
		    unpack_data->point[i].x <= X_MAX &&
		    unpack_data->point[i].y >= Y_MIN &&
		    unpack_data->point[i].y <= Y_MAX &&
		    unpack_data->point[i].z >= Z_MIN &&
		    unpack_data->point[i].z <= Z_MAX )
		{
			row = (int)((unpack_data->point[i].x + X_MAX) / COFF_X_GRID) % GRID_MAX;
			col = (int)((unpack_data->point[i].y + Y_MAX) / COFF_Y_GRID) % GRID_MAX;
			
			
			//printf("length = %ld\n", grid_cell[row][col]->length);
			j = grid_cell[row][col]->length;
			grid_cell[row][col]->point3[j].x = unpack_data->point[i].x;
			grid_cell[row][col]->point3[j].y = unpack_data->point[i].y;
			grid_cell[row][col]->point3[j].z = unpack_data->point[i].z;
			grid_cell[row][col]->length++;

			if( grid_cell[row][col]->point3[j].z > grid_cell[row][col]->max)
				grid_cell[row][col]->max = grid_cell[row][col]->point3[j].z;

			if( grid_cell[row][col]->point3[j].z < grid_cell[row][col]->min)
				grid_cell[row][col]->min = grid_cell[row][col]->point3[j].z;
		}

}

void grid_filter_by_percent(point_grid_t* grid_cell[GRID_MAX][GRID_MAX], float coff_cut)
{
	int i, row = 0, col = 0;
	float dis;
	for (row = 0; row < GRID_MAX; row++)
		for(col = 0; col < GRID_MAX; col++)
		{
			dis = (grid_cell[row][col]->max - grid_cell[row][col]->min) * coff_cut + grid_cell[row][col]->min;
			
			for ( i=0; i < grid_cell[row][col]->length; i++)
				if( grid_cell[row][col]->point3[i].z < dis)
				{
					
					for( int j = i; j+1 < grid_cell[row][col]->length; j++)
					{
						grid_cell[row][col]->point3[j].x = 
							grid_cell[row][col]->point3[j+1].x;

						grid_cell[row][col]->point3[j].y = 
							grid_cell[row][col]->point3[j+1].y;

						grid_cell[row][col]->point3[j].z = 
							grid_cell[row][col]->point3[j+1].z;

											}
					grid_cell[row][col]->length--;
					i--;
					//printf("length = %ld\n", grid_cell[row][col]->length);
				}

			
					
		}
}


void grid_filter_by_distance(point_grid_t* grid_cell[GRID_MAX][GRID_MAX])
{
	int i, row = 0, col = 0;
	float dis;
	for (row = 0; row < GRID_MAX; row++)
		for(col = 0; col < GRID_MAX; col++)
		{
			dis = 0.0f;
			/*if(grid_cell[row][col]->length !=0)
			{
				printf("row = %d, col = %d\n", row, col);
				printf("length = %ld\n", grid_cell[row][col]->length);
				printf("max = %f\n", grid_cell[row][col]->max);
				printf("min = %f\n", grid_cell[row][col]->min);
			}*/
			
			for ( i=0; i < grid_cell[row][col]->length; i++)
				if( grid_cell[row][col]->point3[i].z < dis)
				{
					
					
					for( int j = i; j +1 < grid_cell[row][col]->length; j++)
					{
						grid_cell[row][col]->point3[j].x = 
							grid_cell[row][col]->point3[j+1].x;

						grid_cell[row][col]->point3[j].y = 
							grid_cell[row][col]->point3[j+1].y;

						grid_cell[row][col]->point3[j].z = 
							grid_cell[row][col]->point3[j+1].z;

											}
					grid_cell[row][col]->length--;
					i--;
					//printf("dena length = %ld\n", grid_cell[row][col]->length);
				}
			
			/*if(grid_cell[row][col]->length !=0)
			{
				printf("row = %d, col = %d\n", row, col);
				printf("length = %ld\n", grid_cell[row][col]->length);
				printf("max = %f\n", grid_cell[row][col]->max);
				printf("min = %f\n", grid_cell[row][col]->min);
			}*/

			
					
		}
}


