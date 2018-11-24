#ifndef CHEESEPIZZA_H_
#define CHEESEPIZZA_H_

#include "Pizza.h"

class CheesePizza: public Pizza
{
private:

public:
	CheesePizza(){};
	~CheesePizza(){};

	virtual void prepare() ;
	virtual void bake() ;
	virtual void cut() ;
	virtual void box() ;


};

#endif
