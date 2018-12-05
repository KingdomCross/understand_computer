/*
 * @description 
 */

#ifndef LIGHTONCOMMAND_H_
#define LIGHTONCOMMAND_H_

#include "Command.h"
#include "Light.h"

class LightOnCommand: public Command
{
private: 
	Light mLight;

public: 
	LightOnCommand(Light &light);
	~LightOnCommand();
	
	void execute();


};


#endif
