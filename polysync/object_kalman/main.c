#include"obj_kal.h"

#include<time.h>

int main(int argc, char* argv[])
{
	int loop = 100;
	if( argc ==2 )
		loop = atoi(argv[1]);
	srand((unsigned)time(NULL));
		
	struct Q_cor *Q = (struct Q_cor *)malloc(sizeof(struct Q_cor));
	malloc_err_check(Q);
	
	struct R_cor *R = (struct R_cor *)malloc(sizeof(struct R_cor));
	malloc_err_check(R);
	
	struct pre_kal *pre = (struct pre_kal *)malloc(sizeof(struct pre_kal));
	malloc_err_check(pre);
	
	struct update_kal *update  = (struct update_kal *)malloc(sizeof(struct update_kal));
	malloc_err_check(update);
	
	init_QR(Q, R);
	
	int i = 0;
	float tem = 0.0;
	while( i < loop ) {
		tem = (rand()%32767 - 32767/2)*1.0/32767.0;
		
		if (i % 5 == 0  && i != 0)
			tem = 33;
		
		predict_kalman(Q, pre, tem);
		// update_QR(Q, R, tem, tem);
		
		float dis = pre->Xk + tem;
		
		update_kalman(R,update, pre, dis);
		
		printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", dis, pre->Xk, update->X1k, Q->q, R->r);
		
		++i;
	}
	printf("\n");

	free_all(Q, R, pre, update);
	
	return 0;
}
