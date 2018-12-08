/*
 * @description 
 */

#include "PancakeHouseMenu.h"


PancakeHouseMenu::PancakeHouseMenu()
{
	addItem("K&B's Pancake Breakfast",
            "Pancakes with scrambled eggs, and toast",
            true,
            2.99);

    addItem("Regular Pancake Breakfast",
            "Pancakes with fried eggs, sausage",
            false,
            2.99);

    addItem("Blueberry Pancakes",
            "Pancakes make with fresh blueberries",
            true,
            3.49);

    addItem("Waffles",
            "Waffles, with your choice of blueberries or strawberries",
            true,
            3.59);
}

PancakeHouseMenu::~PancakeHouseMenu()
{
	
}


void PancakeHouseMenu::addItem(std::string name,
                               std::string description,
                               bool        vegetarian,
                               double      price)
{
    menuItems.push_back(MenuItem(name, description, vegetarian, price));
}

std::vector<MenuItem> PancakeHouseMenu::getMenuItems()
{
    return menuItems;
}

