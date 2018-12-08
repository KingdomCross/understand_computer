/*
 * @description 
 */
#include <iostream>


#include "GumballMachine.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"
#include "HasQuarterState.h"
#include "SoldState.h"

GumballMachine::GumballMachine(int numberGumballs):
count(numberGumballs)
{
    soldOutState    = new SoldOutState(this);
    noQuarterState  = new NoQuarterState(this);
    hasQuarterState = new HasQuarterState(this);
    soldState       = new SoldState(this);

    if(numberGumballs > 0)
    {
        state = noQuarterState;
    }
}

GumballMachine::~GumballMachine()
{
    delete soldOutState;
    delete noQuarterState;
    delete hasQuarterState;
    delete soldState;
}


void GumballMachine::insertQuarter()
{
    state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
    state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
    state->turnCrank();
    state->dispense();
}

void GumballMachine::setState(State *state)
{
    this->state = state;
}

void GumballMachine::releaseBall()
{
    std::cout << "A gumball comes rolling out the slot ...\n";
    if ( count >= 0)
    {
        count--;
    }
}

State* GumballMachine::getSoldOutState()
{
    return soldOutState;
}

State* GumballMachine::getNoQuarterState()
{
    return noQuarterState;
}

State* GumballMachine::getHasQuarterState()
{
    return hasQuarterState;
}

State* GumballMachine::getSoldState()
{
    return soldState;
}

int GumballMachine::getCount()
{
    return count;
}
