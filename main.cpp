#ifndef MAIN_HPP_
#define MAIN_CPP_

#include<iostream>
#include<string>   

#include "Utilities.hpp"
#include "WeatherStation.hpp"
#include "CurrentWeatherReport.hpp"
#include "WeatherForecastReport.hpp"
#include "WeatherLogger.hpp"

int main (int argc, char ** argv) {
    
    //create weather station
	WeatherStation weatherStation;

    //generate random incoming weather data (normally should be taken from censors)
    setRandomSeed();
    float temp, humid, pres;
    generateWeatherData(temp, humid, pres);
  
    // inform weather station with the new weather data
    WeatherData data(temp, humid, pres); 
    weatherStation.setMeasurements(data);
    message("Current Temperature", weatherStation.getWeatherData().getTemperature());
    message("Current Humidity", weatherStation.getWeatherData().getHumidity());
    message("Current Pressure", weatherStation.getWeatherData().getPressure());

    message("#Observers: ", weatherStation.getNumberOfObservers());
  
    // add observers 
    CurrentWeatherReport displayWeather(weatherStation);
    message("#Observers: ", weatherStation.getNumberOfObservers());
    //WeatherForecastReport* forecast = new WeatherForecastReport(&weatherStation);
    WeatherForecastReport forecast(weatherStation);
    message("#Observers: ", weatherStation.getNumberOfObservers());
    WeatherLogger logger(weatherStation, "weather.log");
    message("#Observers: ", weatherStation.getNumberOfObservers());

    //generate new incoming weather data
    const int nbOfMeasurements = 1; 
    int cnt = 0;
    while(cnt!=nbOfMeasurements) {
            generateWeatherData(temp, humid, pres);
            data.setWeatherData(temp,humid, pres);
            weatherStation.setMeasurements(data);
            cnt++;
    }

    //remove an observer
    //delete forecast;
    forecast.unregisterFromStation();
    message("Is forecast registered? ", weatherStation.isRegistered(&forecast));

    //generate new incoming weather data
    cnt = 0;
    while(cnt!=nbOfMeasurements) {
            generateWeatherData(temp, humid, pres);
            data.setWeatherData(temp,humid, pres);
            weatherStation.setMeasurements(data);
            cnt++;
    }

    //re-add forecast observer
    forecast.registerToStation();
    message("Is forecast registered? ", weatherStation.isRegistered(&forecast));

    //TODO add debugging methods e.g. that print the #ofObservers

    //Observer Ideas:
    //Logger that writes to file -> YES!
    //Extreme Temperature Alarm -> YES!
    //Maybe Forecast then reads from the Log file
    //can write in binary or other format file
    //better way to get a forecast? use some more advanced math?
}

#endif