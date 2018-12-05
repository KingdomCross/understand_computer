/*
 * @description 
 */

#ifndef TURKEYADAPTER_H_
#define TURKEYADAPTER_H_

#include "Duck.h"
#include "Turkey.h"

class TurkeyAdapter: public Duck 
{
private: 
    Turkey *turkey;

public: 
	TurkeyAdapter(Turkey *turkey);
    virtual	~TurkeyAdapter();
    void quack();
    void fly();

};


#endif
