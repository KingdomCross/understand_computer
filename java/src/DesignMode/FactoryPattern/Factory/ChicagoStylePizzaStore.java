package DesignMode.FactoryPattern.Factory;

public class ChicagoStylePizzaStore extends PizzaStore
{

    @Override
    Pizza createPizza(String type) {
        Pizza pizza = null;

        if(type.equals("cheese"))
        {
            pizza = new ChicagoStyleCheesePizza();
        } 
        else if(type.equals("calm"))
        {
            pizza = new ChicagoStyleCalmPizza();
        }
        return pizza;
    }
}