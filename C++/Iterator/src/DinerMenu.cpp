/*
 * @description 
 */

#include "DinerMenu.h"


DinerMenu::DinerMenu():
    numberOfItems(0)
{
	addItem("Vegetarian BLE",
            "(Fakin') Bacon with lettuce & tomato on whole wheat",
            true,
            2.99);

    addItem("BLT",
            "Bacon with lettuce & tomato on whole wheat", 
            false,
            2.99);

    addItem("Soup of the day",
            "Soup of the day, with a side of potato salas",
            false,
            3.29);

    addItem("Hotdog",
            "A hot dog, with saurkraut, relish, onions, topped with cheese",
            false,
            3.05);

}

DinerMenu::~DinerMenu()
{
	
}

void DinerMenu::addItem(std::string name,
                        std::string description,
                        bool        vegetarian,
                        double      price)
{
    if (numberOfItems >= MAX_ITEMS)
    {
        std::cout << "Sorry, menu is full! Can't add item to menu\n";
    }
    else
    {
        menuItems[numberOfItems] = MenuItem(name, description, vegetarian, price);
        numberOfItems++;
    }

}


decltype(std::array<MenuItem, MAX_ITEMS>) DinerMenu::getMenuItems()
{
    return menuItems;
}


