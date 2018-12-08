/*
 * @description 
 */

#ifndef GUMBALLMACHINE_H_
#define GUMBALLMACHINE_H_

#include "State.h"

class GumballMachine//: public SOMECLASS
{
private: 
    State *soldOutState;
    State *noQuarterState;
    State *hasQuarterState;
    State *soldState;

    State *state;
    int count;
    

public: 
	GumballMachine(int numberGumballs);
	~GumballMachine();
    
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void setState(State *state);
    void releaseBall();
    State* getHasQuarterState();
    State* getSoldOutState();
    State* getNoQuarterState();
    State* getSoldState();
    int    getCount();
};


#endif
