/*
 * @description 
 */

#include <iostream>

#include "SimpleRemoteControl.h"
#include "Light.h"
#include "LightOnCommand.h"
#include "GarageDoor.h"
#include "GarageDoorOpenCommand.h"

int main(int argc, char* argv[])
{
	//std::cout << "Hello main !!!" << std::endl;	
	
	SimpleRemoteControl *remote = new SimpleRemoteControl();
	Light *light = new Light();
	LightOnCommand *lightOn = new LightOnCommand(*light);
	
	remote->setCommand(lightOn);
	remote->buttonWasPressed();
	
	std::cout << std::endl;	
	
	GarageDoor *garageDoor = new GarageDoor();
	GarageDoorOpenCommand *doorOpen = new GarageDoorOpenCommand(garageDoor);

	remote->setCommand(doorOpen);
	remote->buttonWasPressed();
	
	return 0;
}
