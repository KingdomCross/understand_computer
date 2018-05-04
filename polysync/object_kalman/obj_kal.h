#ifndef OBJ_KAL_H_
#define OBJ_KAL_H_

#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

const static float T = 0.02;

static float Q0 = 0.0;
static float R0 = 0.0;
static float Xk0 = 100.0;
static float Pk0 = 5.0;

struct Q_cor {
	float avg;
	float q;
	long size;
};

struct R_cor {
	float avg;
	float r;
	long size;
};

struct pre_kal {
	float Pk;
	float Xk;
};

struct update_kal {
	float K;
	float X1k;
	float P1k;
};

void predict_kalman(struct Q_cor *Q, struct pre_kal *pre, float Uk);
void update_kalman(struct R_cor *R, struct update_kal *update, struct pre_kal *pre, float Zk);

void init_all();
void free_all(struct Q_cor *Q, struct R_cor *R, struct pre_kal *pre, struct update_kal *update);

void init_QR(struct Q_cor *Q, struct R_cor *R);
void update_QR(struct Q_cor *Q, struct R_cor *R, float num1, float num2);

void malloc_err_check(void *p);

#endif
