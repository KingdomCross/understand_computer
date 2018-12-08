/*
 * @description 
 */

#include "MenuItem.h"


MenuItem::MenuItem(std::string name,
                   std::string description,
                   bool        vegetarian,
                   double      price):
                   name(name),
                   description(description),
                   vegetarian(vegetarian),
                   price(price)
{
	
}

MenuItem::MenuItem():
    name(""),
    description(""),
    vegetarian(false),
    price(0.0)
{

}

MenuItem::~MenuItem()
{
	
}


std::string MenuItem::getName()
{
    return name;
}


std::string MenuItem::getDescription()
{
    return description;
}

bool MenuItem::isVegetarian()
{
    return vegetarian;
}

double MenuItem::getPrice()
{
    return price;
}


