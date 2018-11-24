#include "PizzaStore.h"

PizzaStore::PizzaStore(std::string type)
{
	this->type = type;
}

PizzaStore::PizzaStore(SimplePizzaFactory *factory)
{
	this->factory = factory;
}

PizzaStore::~PizzaStore()
{

}

Pizza* PizzaStore::orderPizza()
{
	Pizza *pizza;

	pizza = SimplePizzaFactory::createPizza(type);

	pizza->prepare();
	pizza->bake();
	pizza->cut();
	pizza->box();

	return pizza;
}

Pizza* PizzaStore::orderPizza(std::string type)
{
	Pizza *pizza;

	pizza = factory->createPizza(type);

	pizza->prepare();
	pizza->bake();
	pizza->cut();
	pizza->box();

	return pizza;
}


void PizzaStore::setPizzaType(std::string type)
{
	this->type = type;
}
