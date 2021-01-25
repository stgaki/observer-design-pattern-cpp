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
    message("#Observers: ", weatherStation.getNumberOfObservers()); //should be 0

    //generate incoming weather data (normally should be taken from censors)
    setRandomSeed();
    float temp, humid, pres;
    generateWeatherData(temp, humid, pres);
  
    // inform weather station with the new weather data
    WeatherData data(temp, humid, pres); 
    weatherStation.setMeasurements(data);
  
    // add observers 
    CurrentWeatherReport displayWeather(weatherStation);
    WeatherForecastReport forecast(weatherStation);
    WeatherLogger logger(weatherStation, "weather.log");
    message("#Observers: ", weatherStation.getNumberOfObservers()); //should be 3

    //generate new incoming weather data using forecast hint
    message("Forecast data available? ", weatherStation.isRegistered(&forecast));
    const int nbOfMeasurements = 5; // number of sets of data to generate
    int cnt = 0;
    while(cnt!=nbOfMeasurements) {
        generateSmartWeatherData(temp, humid, pres, forecast.isPressureDecreasing());
        data.setWeatherData(temp,humid, pres);
        weatherStation.setMeasurements(data);
        cnt++;
    }

    //remove forecast observer
    forecast.unregisterFromStation();
    message("#Observers: ", weatherStation.getNumberOfObservers()); //should be 2

    //generate new incoming weather data (no forecast hint available)
    message("Forecast data available? ", weatherStation.isRegistered(&forecast));
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
    message("#Observers: ", weatherStation.getNumberOfObservers()); //should be 3
}

#endif