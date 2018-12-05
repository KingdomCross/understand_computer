/*
 * @description 
 */

#ifndef SIMPLEREMOTECONTROL_H_
#define SIMPLEREMOTECONTROL_H_

#include "Command.h"

class SimpleRemoteControl//: public SOMECLASS
{
private: 
	Command *slot;

public: 
	SimpleRemoteControl();
	~SimpleRemoteControl();
	
	void setCommand(Command *command);
	void buttonWasPressed();

};


#endif
