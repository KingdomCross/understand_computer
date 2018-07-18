#ifndef NAVIGATION_H_
#define NAVIGATION_H_

#include"serial_open.h"
#include"gps_com.h"
#include"ctrl_com.h"
#include"ps_type.h"
#include <math.h>

#define DIS_LAT_LON 94344.5 // 111.1111*1000*cos(LAT)


double gpsYawCorrector(double gpsYaw);
double tarYawCreator(double endlat, double endlon, double gpslat, double gpslon);
double distanceCal(double beglat, double beglon, double endlat, double endlon, double gpslat, double gpslon);
double distance(double a1, double b1, double a2, double b2);
struct CTRL_MESSAGES* navigation(struct GPS_MESSAGES* gps_msg, double endlat[], double endlon[], double endturn[], int* count);

#endif
