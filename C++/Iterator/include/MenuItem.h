/*
 * @description 
 */

#ifndef MENUITEM_H_
#define MENUITEM_H_

#include <iostream>


class MenuItem//: public SOMECLASS
{
private: 
    std::string name;
    std::string description;
    bool        vegetarian;
    double      price;

public: 
	MenuItem(std::string name,
             std::string description,
             bool vegetarian,
             double price
             );
    MenuItem();
	~MenuItem();
    std::string getName();
    std::string getDescription();
    double getPrice();
    bool isVegetarian();

};


#endif
