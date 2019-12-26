package DesignMode.FactoryPattern.Factory;

public class NYStyleCheesePizza extends Pizza  {
    public NYStyleCheesePizza() {

    }

    public void prepare() {
        System.out.println("prepare NYStyleCheesePizza");
    }

    public void bake() {
        System.out.println("bake NYStyleCheesePizza");
    }

    public void cut() {
        System.out.println("cut NYStyleCheesePizza");
    }

    public void box() {
        System.out.println("box NYStyleCheesePizza");
    }

}
