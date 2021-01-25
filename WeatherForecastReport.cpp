#include <iostream>
#include "WeatherForecastReport.hpp"

WeatherForecastReport::WeatherForecastReport(WeatherStation& weatherStation):
  _weatherStation(weatherStation), 
  _weatherData(0,0,0),
  _previousWeatherData(0,0,0) {   
  _weatherStation.registerObserver(this);
  update(weatherStation.getWeatherData());
}

WeatherForecastReport::~WeatherForecastReport(){
  _weatherStation.removeObserver(this);
}

void WeatherForecastReport::update(WeatherData data) {
  _previousWeatherData = _weatherData;
  _weatherData = data;
  displayForecast();
}

void  WeatherForecastReport::registerToStation() {
  _weatherStation.registerObserver(this);
}

void WeatherForecastReport::unregisterFromStation() {
  _weatherStation.removeObserver(this);
}

//TODO: improve forecast technique  
void WeatherForecastReport::displayForecast() const {
  std::cout << "Forecast: ";
  if(isPressureDecreasing()) std::cout << "Watch out for cooler, rainy weather";
  else std::cout << "Improving weather on the way!"; 
  std::cout << "" << std::endl;
}

bool WeatherForecastReport::isPressureDecreasing() const {
  float currentPressure = _weatherData.getPressure();
  float lastPressure = _previousWeatherData.getPressure();
  if (currentPressure > lastPressure) return false;
  else return true;
}
