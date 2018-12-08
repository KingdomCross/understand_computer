/*
 * @description 
 */

#ifndef HASQUARTERSTATE_H_
#define HASQUARTERSTATE_H_

#include "State.h"
#include "GumballMachine.h"

class HasQuarterState: public State 
{
private: 
    GumballMachine *gumballMachine;

public: 
	HasQuarterState(GumballMachine *gumballMachine);
	~HasQuarterState();

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();

};


#endif
