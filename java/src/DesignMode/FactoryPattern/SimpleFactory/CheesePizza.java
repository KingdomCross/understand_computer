package DesignMode.FactoryPattern.SimpleFactory;

public class CheesePizza extends Pizza {

    public CheesePizza() {

    }

    public void prepare() {
        System.out.println("prepare CheesePizza");
    }

    public void bake() {
        System.out.println("bake CheesePizza");
    }

    public void cut() {
        System.out.println("cut CheesePizza");
    }

    public void box() {
        System.out.println("box CheesePizza");
    }
}
