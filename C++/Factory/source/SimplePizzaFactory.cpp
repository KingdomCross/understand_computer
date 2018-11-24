#include "SimplePizzaFactory.h"
#include "CheesePizza.h"
#include "ClamPizza.h"
#include "PepperoniPizza.h"
#include "VeggiePizza.h"


Pizza* SimplePizzaFactory::createPizza(std::string type)
{
	if ("cheese" == type)
	{
		return (new CheesePizza());
	}
	else if ("pepperoni" == type)
	{
		return new PepperoniPizza();
	}
	else if ("clam" == type)
	{
		return new ClamPizza();
	}
	else if ("veggie" == type)
	{
		return new VeggiePizza();
	}
	else
	{
		std::cout << "Factory can't create: " << type << " Pizza\n"
							<< "So create the default Pizza: CheesePizza\n";
		return new CheesePizza();

	}
}
