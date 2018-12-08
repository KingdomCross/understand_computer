/*
 * @description 
 */

#ifndef SOLDOUTSTATE_H_
#define SOLDOUTSTATE_H_

#include "State.h"
#include "GumballMachine.h"

class SoldOutState: public State
{
private: 
    GumballMachine *gumballMachine;

public: 
	SoldOutState(GumballMachine *gumballMachine);
	~SoldOutState();
    
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();

};


#endif
