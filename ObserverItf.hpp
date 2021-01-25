#ifndef OBSERVERITF_HPP_
#define OBSERVERITF_HPP_

#include "WeatherData.hpp"

class ObserverItf {
  
  public:
    virtual void update(WeatherData data) = 0;
    virtual void registerToStation() = 0;
    virtual void unregisterFromStation() = 0;
};

#endif /* OBSERVERITF_HPP_ */