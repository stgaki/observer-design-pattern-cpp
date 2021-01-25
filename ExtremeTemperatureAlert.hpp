#ifndef EXTREMETEMPERATUREALERT_HPP_
#define EXTREMETEMPERATUREALERT_HPP_

#include "ObserverItf.hpp"
#include "WeatherStation.hpp"
#include "WeatherData.hpp"

// upper and lower limits for extreme temperature
#define T_LOWER_LIMIT 0
#define T_UPPER_LIMIT 35

class ExtremeTemperatureAlert: public ObserverItf {
  
  public:
    ExtremeTemperatureAlert(WeatherStation& weatherStation, float TlowerLimit = T_LOWER_LIMIT, float TupperLimit = T_UPPER_LIMIT);
    virtual ~ExtremeTemperatureAlert();

    virtual void update(WeatherData data) override;
    virtual void registerToStation() override;
    virtual void unregisterFromStation() override;
    
    void checkForExtremeTemperature(float temperature) const;
  
    void setExtremeTemperatureLimits(float TlowerLimit, float TupperLimit);
    float getExtremeTemperatureLowerLimit() const;
    float getExtremeTemperatureUpperLimit() const;

  private:
    WeatherStation& _weatherStation;
    float _TlowerLimit;
    float _TupperLimit;
};

#endif /* EXTREMETEMPERATUREALERT_HPP_ */