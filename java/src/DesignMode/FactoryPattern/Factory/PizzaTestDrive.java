package DesignMode.FactoryPattern.Factory;

public class PizzaTestDrive{
    public static void main(String[] args) {
        PizzaStore nyStore = new NYStylePizzaStore();
        PizzaStore chicPizzaStore = new ChicagoStylePizzaStore();

        nyStore.orderPizza("cheese");

        chicPizzaStore.orderPizza("cheese");
    }
}