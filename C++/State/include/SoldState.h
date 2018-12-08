/*
 * @description 
 */

#ifndef SOLDSTATE_H_
#define SOLDSTATE_H_

#include "State.h"
#include "GumballMachine.h"


class SoldState: public State
{
private: 
    GumballMachine *gumballMachine;

public: 
	SoldState(GumballMachine *gumballMachine);
	~SoldState();
    
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();

};


#endif
