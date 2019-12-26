package DesignMode.FactoryPattern.Factory;

public class ChicagoStyleCalmPizza extends Pizza{
    public ChicagoStyleCalmPizza() {

    }

    public void prepare() {
        System.out.println("prepare ChicagoStyleCalmPizza");
    }

    public void bake() {
        System.out.println("bake ChicagoStyleCalmPizza");
    }

    public void cut() {
        System.out.println("cut ChicagoStyleCalmPizza");
    }

    public void box() {
        System.out.println("box ChicagoStyleCalmPizza");
    }

}
