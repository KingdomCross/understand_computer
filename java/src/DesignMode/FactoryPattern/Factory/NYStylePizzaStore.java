package DesignMode.FactoryPattern.Factory;

public class NYStylePizzaStore extends PizzaStore
{

    @Override
    Pizza createPizza(String type) {
        Pizza pizza = null;

        if(type.equals("cheese"))
        {
            pizza = new NYStyleCheesePizza();
        } 
        else if(type.equals("calm"))
        {
            pizza = new NYStyleCalmPizza();
        }
        return pizza;
    }
    
}