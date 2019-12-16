package DesignMode.ObserverPattern;

import java.util.ArrayList;

public class StatisticsDisplay implements DisplayElement, Observer {
    private final ArrayList<Float> temperatureList;
    private float minTemperature;
    private float maxTemperature;
    private float avgTemperature;

    public StatisticsDisplay(final Subject weatherData) {
        weatherData.registerObserver(this);

        temperatureList = new ArrayList<>();
        minTemperature = Float.MAX_VALUE;
        maxTemperature = Float.MIN_VALUE;
        avgTemperature = (float) 0.0;
    }

    public void update(final float temp, final float humidity, final float pressure) {
        temperatureList.add(temp);
        minTemperature = Float.min(minTemperature, temp);
        maxTemperature = Float.max(maxTemperature, temp);
        float sum = (float) 0.0;
        for (final Float number : temperatureList) {
            sum = sum + number.floatValue();
        }
        avgTemperature = sum / temperatureList.size();
        display();
    }

    public void display() {
        System.out.println("Avg/Max/Min temperature = " + avgTemperature + "/" + maxTemperature + "/" + minTemperature);
    }

}