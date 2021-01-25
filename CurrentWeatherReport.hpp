#ifndef CURRENTWEATHERREPORT_HPP_
#define CURRENTWEATHERREPORT_HPP_

#include "ObserverItf.hpp"
#include "WeatherStation.hpp"
#include "WeatherData.hpp"

class CurrentWeatherReport: public ObserverItf {
  
  public:
    CurrentWeatherReport(WeatherStation& weatherStation);
    virtual ~CurrentWeatherReport();

    virtual void update(WeatherData data) override;
    virtual void registerToStation() override;
    virtual void unregisterFromStation() override;
    
    void displayWeatherReport() const;
  
  private:
    WeatherStation& _weatherStation;
    WeatherData _weatherData;
};

#endif /* CURRENTWEATHERREPORT_HPP_ */