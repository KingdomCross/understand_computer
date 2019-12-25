package DesignMode.FactoryPattern.SimpleFactory;

public class PepperoniPizza extends Pizza {

    public PepperoniPizza() {

    }

    public void prepare() {
        System.out.println("prepare PepperoniPizza");
    }

    public void bake() {
        System.out.println("bake PepperoniPizza");
    }

    public void cut() {
        System.out.println("cut PepperoniPizza");
    }

    public void box() {
        System.out.println("box PepperoniPizza");
    }
}
