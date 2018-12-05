/*
 * @description 
 */

#ifndef WILDTURKEY_H_
#define WILDTURKEY_H_

#include "Turkey.h"

class WildTurkey: public Turkey 
{
private: 


public: 
	WildTurkey();
    virtual	~WildTurkey();
    virtual void gobble();
    virtual void fly();


};


#endif
