/*
 * @description 
 */

#ifndef MALLARDDUCK_H_
#define MALLARDDUCK_H_

#include "Duck.h"

class MallardDuck: public Duck 
{
private: 


public: 
	MallardDuck();
    virtual	~MallardDuck();
    virtual void quack();
    virtual void fly();

};


#endif
