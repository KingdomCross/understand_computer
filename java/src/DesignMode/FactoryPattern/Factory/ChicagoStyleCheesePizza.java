package DesignMode.FactoryPattern.Factory;

public class ChicagoStyleCheesePizza extends Pizza{
    public ChicagoStyleCheesePizza() {

    }

    public void prepare() {
        System.out.println("prepare ChicagoStyleCheesePizza");
    }

    public void bake() {
        System.out.println("bake ChicagoStyleCheesePizza");
    }

    public void cut() {
        System.out.println("cut ChicagoStyleCheesePizza");
    }

    public void box() {
        System.out.println("box ChicagoStyleCheesePizza");
    }

}
