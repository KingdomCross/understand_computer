/*
 * @description 
 */

#include "SimpleRemoteControl.h"


SimpleRemoteControl::SimpleRemoteControl()
{
	
}
SimpleRemoteControl::~SimpleRemoteControl()
{
	
}

void SimpleRemoteControl::setCommand(Command *command)
{
	slot = command;
}

void SimpleRemoteControl::buttonWasPressed()
{
	slot->execute();
}
