#ifndef _GRID_H_
#define _GRID_H_

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>


typedef struct _point3
{
	float x;
	float y;
	float z;
} point3_t;


typedef struct _unpack_point
{
	unsigned long length;
	point3_t point[1000];
} unpack_point_t;

#endif
