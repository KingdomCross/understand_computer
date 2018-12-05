/*
 * @description 
 */

#include <iostream>

#include "Tea.h"
#include "Coffee.h"


int main(int argc, char* argv[])
{
    Tea *tea = new Tea();
    tea->prepareRecipe();

    Coffee *coffee = new Coffee();
    coffee->prepareRecipe();

    delete tea;
    delete coffee;

	return 0;
}
