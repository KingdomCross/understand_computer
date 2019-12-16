package DesignMode.ObserverPattern;

public class CurrentConditionsDisplay implements DisplayElement, Observer {
    private float temperature;
    private float humidity;
    
    public CurrentConditionsDisplay(final Subject weatherData) {
        weatherData.registerObserver(this);
    }

    public void update(final float temp, final float humidity, final float pressure) {
        this.temperature = temp;
        this.humidity = humidity;
        display();
    }

    public void display() {
        System.out.println("Current conditions: " + temperature + "F degrees and " + humidity + "% humidity");
    }
}