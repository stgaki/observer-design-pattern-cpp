#include <iostream>
#include "CurrentWeatherReport.hpp"

CurrentWeatherReport::CurrentWeatherReport(WeatherStation& weatherStation): 
  _weatherStation(weatherStation), 
  _weatherData(0,0,0) { 
  _weatherStation.registerObserver(this);
  update(_weatherStation.getWeatherData()); //display weather data as soon as you register!
}

CurrentWeatherReport::~CurrentWeatherReport(){
   _weatherStation.removeObserver(this); 
}

void CurrentWeatherReport::update(WeatherData data) {
  _weatherData = data;
  displayWeatherReport();
}

void CurrentWeatherReport::registerToStation(){
  _weatherStation.registerObserver(this);
}

void CurrentWeatherReport::unregisterFromStation() {
  _weatherStation.removeObserver(this);
}
    
void CurrentWeatherReport::displayWeatherReport() const{
  std::cout << "Current Conditions: " << _weatherData.getTemperature() << " degrees Celcius, " <<
    _weatherData.getHumidity() << "% humidity, " << _weatherData.getPressure() << " atm barometric pressure" << std::endl;
}