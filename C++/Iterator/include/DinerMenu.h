/*
 * @description 
 */

#ifndef DINERMENU_H_
#define DINERMENU_H_

#include <array>

#include "MenuItem.h"

static const int MAX_ITEMS = 6;

class DinerMenu//: public SOMECLASS
{
private: 
    int             numberOfItems;
    std::array<MenuItem, MAX_ITEMS> menuItems;

public: 
	DinerMenu();
	~DinerMenu();
    
    void addItem(std::string name,
                 std::string description,
                 bool        vegetarian,
                 double      price);

    decltype(std::array<MenuItem, MAX_ITEMS>) getMenuItems();       

};


#endif
