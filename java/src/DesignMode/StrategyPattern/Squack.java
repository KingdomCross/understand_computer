package DesignMode.StrategyPattern;

public class Squack implements QuackBehavior {
    public void quack() {
        System.out.println("Squack");
    }
}