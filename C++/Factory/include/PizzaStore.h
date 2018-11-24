#ifndef PIZZASTORE_H_
#define PIZZASTORE_H_

#include <string>

#include "SimplePizzaFactory.h"


class PizzaStore
{
private:
	SimplePizzaFactory *factory;
	std::string type;

public:
	PizzaStore(std::string type);
	PizzaStore(SimplePizzaFactory *factory);

	~PizzaStore();

	Pizza* orderPizza();
	Pizza* orderPizza(std::string type);

	void setPizzaType(std::string type);

};


#endif
