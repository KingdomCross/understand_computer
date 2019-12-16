package DesignMode.ObserverPattern;

import java.util.ArrayList;

public class WeatherData implements Subject {
    private final ArrayList<Observer> observers;
    private float temperature;
    private float humidity;
    private float pressure;

    public WeatherData() {
        observers = new ArrayList<>();
    }

    public void registerObserver(final Observer o) {
        observers.add(o);
    }

    public void removeObserver(final Observer o) {
        if (!observers.remove(o)) {
            System.out.println("No this Observer");
        }
        ;
    }

    public void notifyObservers() {
        for (final Observer observer : observers) {
            observer.update(temperature, humidity, pressure);
        }
    }

    public void measurementsChanged() {
        notifyObservers();
    }

    public void setMeasurements(final float temperature, final float humidity, final float pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;
        measurementsChanged();
    }
}