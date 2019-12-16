package DesignMode.ObserverPattern;

public class WeatherStation {
    public static void main(final String[] args) {
        final WeatherData weatherData = new WeatherData();

        final CurrentConditionsDisplay currentDisplay = new CurrentConditionsDisplay(weatherData);
        final StatisticsDisplay statisticsDisplay = new StatisticsDisplay(weatherData);
        final ForecastDisplay forcastDisplay = new ForecastDisplay(weatherData);

        weatherData.setMeasurements(60, 65, 56);
        weatherData.setMeasurements(80, 66, 89);
        weatherData.setMeasurements(50, 34, 33);

        weatherData.removeObserver(currentDisplay);
        weatherData.removeObserver(statisticsDisplay);
        weatherData.removeObserver(forcastDisplay);
    }
}