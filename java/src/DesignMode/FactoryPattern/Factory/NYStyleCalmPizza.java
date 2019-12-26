package DesignMode.FactoryPattern.Factory;

public class NYStyleCalmPizza extends Pizza {
    public NYStyleCalmPizza() {

    }

    public void prepare() {
        System.out.println("prepare NYStyleCalmPizza");
    }

    public void bake() {
        System.out.println("bake NYStyleCalmPizza");
    }

    public void cut() {
        System.out.println("cut NYStyleCalmPizza");
    }

    public void box() {
        System.out.println("box NYStyleCalmPizza");
    }

}
