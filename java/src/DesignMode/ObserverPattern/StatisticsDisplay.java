package DesignMode.ObserverPattern;

import java.util.ArrayList;

public class StatisticsDisplay implements DisplayElement, Observer {
    private ArrayList<Float> temperatureList;
    private Subject weatherData;
    private float minTemperature;
    private float maxTemperature;
    private float avgTemperature;

    public StatisticsDisplay(WeatherData weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);

        temperatureList = new ArrayList<>();
        minTemperature = Float.MAX_VALUE;
        maxTemperature = Float.MIN_VALUE;
        avgTemperature = (float) 0.0;
    }
    
    public void update(float temp, float humidity, float pressure) {
        temperatureList.add(temp);
        minTemperature = Float.min(minTemperature, temp);
        maxTemperature = Float.max(maxTemperature, temp);
        float sum = (float) 0.0;
        for (Float number : temperatureList) {
            sum = sum + number.floatValue();
        }
        avgTemperature = sum / temperatureList.size();
        display();
    }

    public void display() {
        System.out.println("Avg/Max/Min temperature = " + avgTemperature + "/" + maxTemperature + "/" + minTemperature);
    }

}