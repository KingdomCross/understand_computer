/*
 * @description 
 */

#ifndef GARAGEDOOROPENCOMMAND_H_
#define GARAGEDOOROPENCOMMAND_H_

#include "GarageDoor.h"
#include "Command.h"

class GarageDoorOpenCommand: public Command
{
private: 
	GarageDoor *m_garageDoor;
	
public: 
	GarageDoorOpenCommand(GarageDoor* garageDoor);
	~GarageDoorOpenCommand();

	void execute();

};


#endif
