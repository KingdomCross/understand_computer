/*
 * @description 
 */
#include <iostream>


#include "HasQuarterState.h"


HasQuarterState::HasQuarterState(GumballMachine *gumballMachine):
gumballMachine(gumballMachine)
{
	
}

HasQuarterState::~HasQuarterState()
{
	
}

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter\n";
}

void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned\n";
    gumballMachine->setState(gumballMachine->getNoQuarterState());
}

void HasQuarterState::turnCrank()
{
    std::cout << "You turned ...\n";
    gumballMachine->setState(gumballMachine->getSoldState());
}


void HasQuarterState::dispense()
{
	std::cout << "No gumball dispensed\n";
}
