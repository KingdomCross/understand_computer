#ifndef SIMPLEPIZZAFACTORY_H_
#define SIMPLEPIZZAFACTORY_H_

#include <string>

#include "Pizza.h"

class SimplePizzaFactory
{
private:

public:
	static Pizza* createPizza(std::string type);

};


#endif
