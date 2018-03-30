#ifndef _PS_TYPE_H_
#define _PS_TYPE_H_

#define CCT (+8)  
#define PI 3.1415926

#define PID_P (-5.0)

typedef long time_t;      /* time value */  

struct GPS_MESSAGES{
	double lat;
	double lon;
	double height;
	float vel_n;
	float vel_e;
	float vel_d;
	float a_X;
	float a_Y;
	float a_Z;
	float gForce;
	float roll;
	float pitch;
	float head;
	float angular_X;
	float angular_Y;
	float angular_Z;
};


struct CTRL_MESSAGES{
	unsigned char speed;
	unsigned char steer;
	unsigned char power;
};

#endif

