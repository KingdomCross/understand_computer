package DesignMode.FactoryPattern.Factory;

public abstract class PizzaStore {
    public PizzaStore() {
    }

    public Pizza orderPizza(String type) {
        Pizza pizza;

        pizza = createPizza(type);
        if (pizza == null) {
            System.out.println("No this type Pizza: " + type);
            return pizza;
        }

        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return pizza;
    }

    abstract Pizza createPizza(String type);
}