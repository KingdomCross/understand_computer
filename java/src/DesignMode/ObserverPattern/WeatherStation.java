package DesignMode.ObserverPattern;

public class WeatherStation {
    public static void main(String[] args) {
        WeatherData weatherData = new WeatherData();

        CurrentConditionsDisplay currentDisplay = new CurrentConditionsDisplay(weatherData);
        StatisticsDisplay statisticsDisplay = new StatisticsDisplay(weatherData);
        ForecastDisplay forcastDisplay = new ForecastDisplay(weatherData);

        weatherData.setMeasurements(60, 65, 56);
        weatherData.setMeasurements(80, 66, 89);
        weatherData.setMeasurements(50, 34, 33);

        weatherData.removeObserver(currentDisplay);
        weatherData.removeObserver(statisticsDisplay);
        weatherData.removeObserver(forcastDisplay);
    }
}