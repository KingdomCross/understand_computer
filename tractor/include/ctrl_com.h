#ifndef _CTRL_COM_H_
#define _CTRL_COM_H_

#include"serial_open.h"
#include"ps_type.h"

void ctrl_send(unsigned char se_buf[], struct CTRL_MESSAGES* send, int fd_ctrl, int len);

#endif
