#ifndef PIZZA_H_
#define PIZZA_H_

#include <iostream>

class Pizza
{
private:

public:
	virtual void prepare() 	= 0;
	virtual void bake() 	= 0;
	virtual void cut() 		= 0;
	virtual void box() 		= 0;


};

#endif
