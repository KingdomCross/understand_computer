package DesignMode.ObserverPattern;

public class ForecastDisplay implements DisplayElement, Observer {
    float oldTemperature = (float) 0.0;
    float currentTemperature = (float) 0.0;

    public ForecastDisplay(Subject weatheData) {
        weatheData.registerObserver(this);
    }

    public void update(float temp, float humidity, float pressure) {
        currentTemperature = temp;
        display();
    }

    public void display() {
        if(oldTemperature < currentTemperature)
        {
            System.out.println("Improving weather on the weather");
        }
        else {
            System.out.println("Watch out for cooler");
        }
        oldTemperature = currentTemperature;
    }
}