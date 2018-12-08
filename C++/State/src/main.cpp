/*
 * @description 
 */

#include <iostream>

#include "GumballMachine.h"

int main(int argc, char* argv[])
{
	//std::cout << "Hello main !!!" << std::endl;	
	
	int gumballNumber = 5;
	GumballMachine gumballMachine(gumballNumber);
	
	gumballMachine.insertQuarter();
	gumballMachine.ejectQuarter();
	gumballMachine.turnCrank();
	std::cout << "\n\n";
	
	gumballMachine.insertQuarter();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	std::cout << "\n\n";
	
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	std::cout << "\n\n";
	
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	std::cout << "\n\n";
	
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	std::cout << "\n\n";
	
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	std::cout << "\n\n";
	
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	std::cout << "\n\n";
	
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	std::cout << "\n\n";
	
	return 0;
}
