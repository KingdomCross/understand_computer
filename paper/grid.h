#ifndef _GRID_H_
#define _GRID_H_

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#define GRID_MAX 200   
#define CELL_NUM_MAX 900
//#define PACK_NUM_MAX 100
//#define PACK_POINT_NUM 384
#define POINTS_MAX 1000

static const float DISTANCE_MAX = 150.0f;
static const float X_MAX =  DISTANCE_MAX/2.0;     // (Meters)
static const float Y_MAX =  DISTANCE_MAX/5.0;     // (Meters)
static const float Z_MAX =  DISTANCE_MAX/15.0;     // (Meters)

static const float X_MIN =  0;     // (Meters)
static const float Y_MIN = -DISTANCE_MAX/5;     // (Meters)
static const float Z_MIN = -DISTANCE_MAX/15.0;     // (Meters)

static const float COFF_CUT_OFF = 0.05f;	      // filter parameters
static const float COFF_X_GRID = (X_MAX - X_MIN)/GRID_MAX;
static const float COFF_Y_GRID = (Y_MAX - Y_MIN)/GRID_MAX;

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
