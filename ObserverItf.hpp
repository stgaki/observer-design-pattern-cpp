#ifndef OBSERVERITF_HPP_
#define OBSERVERITF_HPP_

#include "WeatherData.hpp"

//TODO rename to WeatherStationObserverItf
//maybe add a WeatherStationObserver class that keeps the WeatherStation* _weatherStation;
// and  WeatherData _weatherData; and constructs them
//then eg. currentWeatherReport can only implement update..
// or WeatherStationObserverItf can have members.. can an interface have members? protected?
class ObserverItf {
  
  public:
    virtual void update(WeatherData data) = 0;
    virtual void registerToStation() = 0;
    virtual void unregisterFromStation() = 0;
};

#endif /* OBSERVERITF_HPP_ */