/*
 * @description 
 */

#ifndef PANCAKEHOUSEMENU_H_
#define PANCAKEHOUSEMENU_H_
#include <vector>

#include "MenuItem.h"

class PancakeHouseMenu//: public SOMECLASS
{
private: 
    std::vector<MenuItem> menuItems;

public: 
	PancakeHouseMenu();
	~PancakeHouseMenu();
    
    void addItem(std::string name,
                 std::string description,
                 bool        vegetarian,
                 double      price);

    std::vector<MenuItem> getMenuItems();

};


#endif
