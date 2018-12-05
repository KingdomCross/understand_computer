/*
 * @description 
 */

#include <iostream>

#include "MallardDuck.h"
#include "WildTurkey.h"
#include "TurkeyAdapter.h"


int main(int argc, char* argv[])
{
	
    MallardDuck *duck = new MallardDuck();
    WildTurkey *turkey = new WildTurkey();
    Duck *turkeyAdapter = new TurkeyAdapter(turkey);

    std::cout <<"The turkey says ...\n";
    turkey->gobble();
    turkey->fly();

    std::cout << "The Duck says ...\n";
    duck->quack();
    duck->fly();

    std::cout << "The TurkeyAdapter says ... \n";
    turkeyAdapter->quack();
    turkeyAdapter->fly();
    
    delete duck;
    delete turkey;
    delete turkeyAdapter;

	return 0;
}
