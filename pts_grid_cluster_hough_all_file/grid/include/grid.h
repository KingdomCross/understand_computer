#ifndef _GRID_H_
#define _GRID_H_

#include<stdlib.h>
#include<stdio.h>

#define GRID_MAX 10   
#define CELL_NUM_MAX 900
#define POINTS_MAX 1200

#define DISTANCE_MAX (150.0f)

#define X_MAX (DISTANCE_MAX/2.0)
#define Y_MAX (DISTANCE_MAX/5.0)
#define Z_MAX (DISTANCE_MAX/15.0)

#define X_MIN (0.0f)
#define Y_MIN (-DISTANCE_MAX/5)
#define Z_MIN (-DISTANCE_MAX/15.0)

#define COFF_CUT_OFF (0.4f)
#define COFF_X_GRID ((X_MAX - X_MIN)/GRID_MAX)
#define COFF_Y_GRID ((Y_MAX - Y_MIN)/GRID_MAX)

typedef struct _point3
{
	float x;
	float y;
	float z;
} point3_t;


typedef struct _unpack_point
{
	unsigned long length;
	point3_t point[POINTS_MAX];
} unpack_point_t;

// store data has filtered second
typedef struct _point_grid
{
	float max;
	float min;
	volatile unsigned long length;
	point3_t point3[CELL_NUM_MAX];
} point_grid_t;

void grid_cell_memory(point_grid_t* grid_cell[GRID_MAX][GRID_MAX]);
void grid_cell_init(point_grid_t* grid_cell[GRID_MAX][GRID_MAX]);
void grid_cell_memory_free(point_grid_t* grid_cell[GRID_MAX][GRID_MAX]);
void grid_cell_output(point_grid_t* grid_cell[GRID_MAX][GRID_MAX],FILE  *fp3);
void grid_on(unpack_point_t* unpack_data, point_grid_t* grid_cell[GRID_MAX][GRID_MAX] );
void grid_filter_by_percent(point_grid_t* grid_cell[GRID_MAX][GRID_MAX], float coff_cut);
void grid_filter_by_distance(point_grid_t* grid_cell[GRID_MAX][GRID_MAX]);

#endif
