/*
 * @description 
 */
#include <iostream>


#include "CaffeineBeverage.h"


CaffeineBeverage::CaffeineBeverage()
{
	
}

CaffeineBeverage::~CaffeineBeverage()
{
	
}

void CaffeineBeverage::prepareRecipe()
{
    boilWater();
    brew();
    pourInCup();
    addCondiments();
}

void CaffeineBeverage::boilWater()
{
    std::cout << "Boiling water\n";
}

void CaffeineBeverage::pourInCup()
{
    std::cout << "Pouring into cup\n";
}

void CaffeineBeverage::brew()
{
}

void CaffeineBeverage::addCondiments()
{
}

