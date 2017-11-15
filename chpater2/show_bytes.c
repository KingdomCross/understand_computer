#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
	int i;
	for(i=0; i < len; i++)
		printf("%.2x",start[i]);
	
	printf("\n");
	
}

void show_int(int x)
{
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer) &x, sizeof(void*));
}

void test_show_bytes(int val)
{	
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
	
}

	
int main(int argc, char* argv[])
{
	
	if(argc !=2)
		printf("the parameter must be one!\n");
	else
		test_show_bytes(atoi(argv[1]));
		
	return 0;

}
