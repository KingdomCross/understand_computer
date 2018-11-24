#ifndef CLAMPIZZA_H_
#define CLAMPIZZA_H_

#include "Pizza.h"

class ClamPizza: public Pizza
{
private:

public:
	ClamPizza(){};
	~ClamPizza(){};

	virtual void prepare() ;
	virtual void bake() ;
	virtual void cut() ;
	virtual void box() ;


};

#endif
