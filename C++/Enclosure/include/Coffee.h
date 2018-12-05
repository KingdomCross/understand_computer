/*
 * @description 
 */

#ifndef COFFEE_H_
#define COFFEE_H_

#include "CaffeineBeverage.h"

class Coffee: public CaffeineBeverage 
{
private: 


public: 
	Coffee();
    virtual	~Coffee();
    virtual void brew();
    virtual void addCondiments();

};


#endif
