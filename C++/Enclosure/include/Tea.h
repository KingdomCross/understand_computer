/*
 * @description 
 */

#ifndef TEA_H_
#define TEA_H_

#include "CaffeineBeverage.h"


class Tea: public CaffeineBeverage 
{
private: 


public: 
	Tea();
    virtual	~Tea();
    virtual void brew();
    virtual void addCondiments();

};


#endif
