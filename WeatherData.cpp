#include "WeatherData.hpp"

WeatherData::WeatherData(float temperature, float humidity, float pressure): 
  _temperature(temperature), _humidity(humidity), _pressure(pressure) {
  
}
  
void WeatherData::setTemperature(const float temperature){
  _temperature = temperature;  
}

void WeatherData::setHumidity(const float humidity){
  _humidity = humidity;
}

void WeatherData::setPressure(const float pressure){
  _pressure = pressure;
}

void WeatherData::setWeatherData(const float temperature, const float humidity, const float pressure){
  setTemperature(temperature);
  setHumidity(humidity);
  setPressure(pressure);
}

float WeatherData::getTemperature() const{
  return _temperature;
}

float WeatherData::getHumidity() const{
  return _humidity;
}

float WeatherData::getPressure() const{
  return _pressure;
}