#include <algorithm> 
#include "WeatherStation.hpp"

WeatherStation::WeatherStation(): _weatherData(0,0,0) {
}

WeatherStation::WeatherStation(WeatherData data): _weatherData(data) {
}

WeatherStation::~WeatherStation(){
}

void WeatherStation::registerObserver(ObserverItf* observer){
  if(!isRegistered(observer)) _observers.push_back(observer);
}

void WeatherStation::removeObserver(ObserverItf* observer){
 if(isRegistered(observer)) _observers.remove(observer);
}

void WeatherStation::notifyObservers(){
  for(auto obsIt = _observers.begin(), end = _observers.end(); obsIt!=end; ++obsIt){
    (*obsIt)->update(_weatherData);
  }
}

bool WeatherStation::isRegistered(ObserverItf* observer) const {
  auto it = find(_observers.begin(), _observers.end(), observer);
  if(it == _observers.end()) return false;
  else return true;
}

void WeatherStation::setMeasurements(WeatherData weatherData){
  _weatherData = weatherData;
  notifyObservers();
}

WeatherData WeatherStation::getWeatherData() const {
  return _weatherData;
}


int WeatherStation::getNumberOfObservers() const {
  return _observers.size();
}
