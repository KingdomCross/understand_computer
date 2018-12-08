/*
 * @description 
 */

#include <iostream>

#include "PancakeHouseMenu.h"
#include "DinerMenu.h"


int main(int argc, char* argv[])
{
	std::cout << "Hello main !!!" << std::endl;	
    
    DinerMenu diner;
    std::array<MenuItem, 6> arr;
    arr = diner.getMenuItems();


	return 0;
}
