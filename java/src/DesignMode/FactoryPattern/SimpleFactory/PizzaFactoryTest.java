package DesignMode.FactoryPattern.SimpleFactory;

public class PizzaFactoryTest
{
    public static void main(String[] args) {
        SimplePizzaFactory factory = new SimplePizzaFactory();
        PizzaStore store = new PizzaStore(factory);

        store.orderPizza("cheese");
        
        store.orderPizza("ce");

        store.orderPizza("pepperoni");
    }
}