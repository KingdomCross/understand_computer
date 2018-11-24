#ifndef VEGGIEPIZZA_H_
#define VEGGIEPIZZA_H_

#include "Pizza.h"

class VeggiePizza: public Pizza
{
private:

public:
	VeggiePizza(){};
	~VeggiePizza(){};

	virtual void prepare() ;
	virtual void bake() ;
	virtual void cut() ;
	virtual void box() ;


};

#endif
