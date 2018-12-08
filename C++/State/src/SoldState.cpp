/*
 * @description 
 */
#include <iostream>


#include "SoldState.h"


SoldState::SoldState(GumballMachine *gumballMachine):
gumballMachine(gumballMachine)
{
	
}

SoldState::~SoldState()
{
	
}

void SoldState::insertQuarter()
{
    std::cout << "Please wait, we are already giving you a gumball\n";
}

void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank\n";
}

void SoldState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball\n";
}

void SoldState::dispense()
{
    gumballMachine->releaseBall();
    if(gumballMachine->getCount() >= 0)
    {
        gumballMachine->setState(gumballMachine->getNoQuarterState());
    }
    else
    {
        std::cout << "Oops, out of gumballs!\n";
        gumballMachine->setState(gumballMachine->getSoldOutState());
    }
    
}


