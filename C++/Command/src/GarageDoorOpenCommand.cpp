/*
 * @description 
 */

#include "GarageDoorOpenCommand.h"


GarageDoorOpenCommand::GarageDoorOpenCommand(GarageDoor *garageDoor):
m_garageDoor(garageDoor)
{
	
}

GarageDoorOpenCommand::~GarageDoorOpenCommand()
{
	
}

void GarageDoorOpenCommand::execute()
{
	m_garageDoor->up();
	m_garageDoor->lightOn();
}
