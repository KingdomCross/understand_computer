#include"write_files.h"

void write_file(struct GPS_MESSAGES* gps_msg, struct CTRL_MESSAGES* ctrl_msg, FILE* f){
	int duphandle;
	
	
  	time_t rawtime;  
  	struct tm * ptm;  
  	time(&rawtime);  
  	ptm = gmtime(&rawtime);  
  	fprintf (f, "%2d\t%02d\t%02d\t", (ptm->tm_hour+CCT)%24, ptm->tm_min, ptm->tm_sec); 
	
	fprintf(f,"%.8lf\t%.8lf%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t%.8lf\t", 
				gps_msg->lat, 
				gps_msg->lon, 
				gps_msg->height, 
				gps_msg->vel_n, 
				gps_msg->vel_e, 
				gps_msg->vel_d, 
				gps_msg->a_X, 
				gps_msg->a_Y, 
				gps_msg->a_Z, 
				gps_msg->gForce,
				gps_msg->roll, 
				gps_msg->pitch, 
				gps_msg->head, 
				gps_msg->angular_X, 
				gps_msg->angular_Y, 
				gps_msg->angular_Z
				 );
	fprintf(f,"%d\t%d\t%d\n\n",
				ctrl_msg->speed, 
				ctrl_msg->steer, 
				ctrl_msg->power
			);
	
	fflush(f);
	duphandle = dup(fileno(f));
	close(duphandle);			
}

