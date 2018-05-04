#include"obj_kal.h"

void predict_kalman(struct Q_cor *Q, struct pre_kal *pre, float Uk)
{

	pre->Xk = Xk0 - T * Uk;
	pre->Pk = Pk0 - Q->q;
	Xk0 = pre->Xk;
	Pk0 = pre->Pk;
	
}


void update_kalman(struct R_cor *R, struct update_kal *update, struct pre_kal *pre, float Zk)
{

	update->K   = pre->Pk / ( pre->Pk + R->r);
	update->X1k = pre->Xk + update->K * ( Zk - pre->Xk);
	update->P1k = pre->Pk - update->K * pre->Pk;
	
}

void init_QR(struct Q_cor *Q, struct R_cor *R)
{
	Q->q = Q0;
	Q->avg = 0;
	Q->size = 0;
	
	R->r = R0;
	R->avg = 0;
	R->size = 0;
}

void update_QR(struct Q_cor *Q, struct R_cor *R, float num1, float num2)
{
	Q->q = Q->q + (Q->avg - num1) * (Q->avg - num1);
	Q->avg = ((Q->avg * Q->size) + num1) / (Q->size + 1);
	Q->size++;
	
	R->r = R->r + (R->avg - num1) * (R->avg - num1);
	R->avg = ((R->avg * R->size) + num1) / (R->size + 1);
	R->size++;
	
}


void free_all(struct Q_cor *Q, struct R_cor *R, struct pre_kal *pre, struct update_kal *update)
{
	free(Q);
	free(R);
	free(pre);
	free(update);

}

void malloc_err_check(void *p)
{
	if( p = NULL) { 
		printf("malloc error\n");
		exit(0);
	}
}

