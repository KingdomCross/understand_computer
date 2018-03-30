#ifndef _WRITE_FILES_H_
#define _WRITE_FILES_H_

#include<stdio.h>
#include<unistd.h>
#include <time.h>
#include"ps_type.h"


void write_file(struct GPS_MESSAGES* gps_msg, struct CTRL_MESSAGES* ctrl_msg, FILE* f);

#endif
