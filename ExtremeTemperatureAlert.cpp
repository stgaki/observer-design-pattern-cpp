#include <iostream>
#include "ExtremeTemperatureAlert.hpp"

ExtremeTemperatureAlert::ExtremeTemperatureAlert(WeatherStation& weatherStation, 
 const float TlowerLimit, const float TupperLimit): 
  _weatherStation(weatherStation),
  _TlowerLimit(TlowerLimit),
  _TupperLimit(TupperLimit) { 
  _weatherStation.registerObserver(this);
  update(_weatherStation.getWeatherData()); // check for extreme temperature immediately  
}

ExtremeTemperatureAlert::~ExtremeTemperatureAlert(){
   _weatherStation.removeObserver(this); 
}

void ExtremeTemperatureAlert::update(WeatherData data) {
  checkForExtremeTemperature(data.getTemperature());
}

void ExtremeTemperatureAlert::registerToStation(){
  _weatherStation.registerObserver(this);
}

void ExtremeTemperatureAlert::unregisterFromStation() {
  _weatherStation.removeObserver(this);
}
  
void ExtremeTemperatureAlert::setExtremeTemperatureLimits(float TlowerLimit, float TupperLimit){
  _TlowerLimit = TlowerLimit;
  _TupperLimit = TupperLimit; 
}

float ExtremeTemperatureAlert::getExtremeTemperatureLowerLimit() const {
    return _TlowerLimit;
}
float ExtremeTemperatureAlert::getExtremeTemperatureUpperLimit() const {
    return _TupperLimit;
}
    
void ExtremeTemperatureAlert::checkForExtremeTemperature(float temperature) const{
     if(temperature < _TlowerLimit) std::cout << "EXTREME TEMPERATURE ALARM: Beware for extreme cold!" << std::endl;
     else if (temperature > _TupperLimit ) std::cout << "EXTREME TEMPERATURE ALARM: Beware for extreme heat!" << std::endl;
}