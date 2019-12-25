package DesignMode.FactoryPattern.SimpleFactory;

public class PizzaStore
{
    SimplePizzaFactory factory;

    public PizzaStore(SimplePizzaFactory factory)
    {
        this.factory = factory;
    }

    public Pizza orderPizza(String type)
    {
        Pizza pizza;

        pizza = factory.createPizza(type);
        if(pizza ==null)
        {
            System.out.println("No this type Pizza: " + type);
            return pizza;
        }

        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return pizza;
    }
}