/*
 * @description 
 */

#include "LightOnCommand.h"


LightOnCommand::LightOnCommand(Light &light):
mLight(light)
{
	
}

LightOnCommand::~LightOnCommand()
{
	
}

void LightOnCommand::execute()
{
	mLight.on();
}
