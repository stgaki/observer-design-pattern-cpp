#ifndef MAIN_HPP_
#define MAIN_CPP_

#include<iostream>
#include<string>   

#include "Utilities.hpp"
#include "WeatherStation.hpp"
#include "CurrentWeatherReport.hpp"
#include "ExtremeTemperatureAlert.hpp"
#include "WeatherForecastReport.hpp"
#include "WeatherLogger.hpp"

int main (int argc, char ** argv) {
    
    //create weather station
	WeatherStation weatherStation;
    utils::message("#Observers: ", weatherStation.getNumberOfObservers()); //should be 0

    //generate incoming weather data (normally should be taken from censors)
    utils::setRandomSeed();
    float temp, humid, pres;
    utils::generateWeatherData(temp, humid, pres);
  
    // inform weather station with the new weather data
    WeatherData data(temp, humid, pres); 
    weatherStation.setMeasurements(data);
  
    // add observers 
    CurrentWeatherReport displayWeather(weatherStation);
    ExtremeTemperatureAlert temperatureAlarm(weatherStation);
    WeatherForecastReport forecast(weatherStation);
    WeatherLogger logger(weatherStation, "weather.log");
    utils::message("#Observers: ", weatherStation.getNumberOfObservers()); //should be 4

    //generate new incoming weather data using forecast hint
    utils::message("Forecast data available? ", weatherStation.isRegistered(&forecast));
    const int nbOfMeasurements = 5; // number of sets of data to generate
    int cnt = 0;
    while(cnt!=nbOfMeasurements) {
        utils::generateSmartWeatherData(temp, humid, pres, forecast.isPressureDecreasing());
        data.setWeatherData(temp,humid, pres);
        weatherStation.setMeasurements(data);
        cnt++;
    }

    //remove forecast observer
    forecast.unregisterFromStation();
    utils::message("#Observers: ", weatherStation.getNumberOfObservers()); //should be 3

    //generate new incoming weather data (no forecast hint available)
    utils::message("Forecast data available? ", weatherStation.isRegistered(&forecast));
    cnt = 0;
    while(cnt!=nbOfMeasurements) {
        utils::generateWeatherData(temp, humid, pres);
        data.setWeatherData(temp,humid, pres);
        weatherStation.setMeasurements(data);
        cnt++;
    }

    //re-add forecast observer
    forecast.registerToStation();
    utils::message("#Observers: ", weatherStation.getNumberOfObservers()); //should be 4
    utils::message("Forecast data available? ", weatherStation.isRegistered(&forecast));
}

#endif