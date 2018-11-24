#include <iostream>

#include "PizzaStore.h"

int main(int argc, char* argv[])
{
	PizzaStore pizzaStore("cheese");
	pizzaStore.orderPizza();

	std::cout << "\n\n";

	SimplePizzaFactory *factory = new SimplePizzaFactory();
	PizzaStore pizzaStore2(factory);
	pizzaStore2.orderPizza("clam");

	std::cout << "\n\n";

	pizzaStore.setPizzaType("DEAN");
	pizzaStore.orderPizza();

	return 0;
}
