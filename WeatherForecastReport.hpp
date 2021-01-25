#ifndef WEATHERFORECASTREPORT_HPP_
#define WEATHERFORECASTREPORT_HPP_

#include "ObserverItf.hpp"
#include "WeatherStation.hpp"

class WeatherForecastReport: public ObserverItf {
  
  public:
    WeatherForecastReport(WeatherStation& weatherStation);
    virtual ~WeatherForecastReport();

    virtual void update(WeatherData data) override;
    virtual void registerToStation() override;
    virtual void unregisterFromStation() override;

    void displayForecast() const;
    bool isPressureDecreasing() const;
  
  private:
    WeatherStation& _weatherStation;
    WeatherData _weatherData;
    WeatherData _previousWeatherData;
};

#endif  /* WEATHERFORECASTREPORT_HPP_ */