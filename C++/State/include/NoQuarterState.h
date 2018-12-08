/*
 * @description 
 */

#ifndef NOQUARTERSTATE_H_
#define NOQUARTERSTATE_H_

#include "State.h"
#include "GumballMachine.h"

class NoQuarterState: public State 
{
private: 
    GumballMachine *gumballMachine;

public: 
	NoQuarterState(GumballMachine *gumballMachine);
	~NoQuarterState();
    
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();

};


#endif
