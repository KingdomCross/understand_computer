#ifndef PEPPERONIPIZZA_H_
#define PEPPERONIPIZZA_H_

#include "Pizza.h"

class PepperoniPizza: public Pizza
{
private:

public:
	PepperoniPizza(){};
	~PepperoniPizza(){};

	virtual void prepare() ;
	virtual void bake() ;
	virtual void cut() ;
	virtual void box() ;


};

#endif
