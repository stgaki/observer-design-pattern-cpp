#ifndef WEATHERLOGGER_HPP_
#define WEATHERLOGGER_HPP_

#include <string>
#include "ObserverItf.hpp"
#include "WeatherStation.hpp"

class WeatherLogger: public ObserverItf {
  
  public:
    WeatherLogger(WeatherStation& weatherStation, std::string outputFilename);
    virtual ~WeatherLogger();

    virtual void update(WeatherData data) override;
    virtual void registerToStation() override;
    virtual void unregisterFromStation() override;

    void logToFile(WeatherData data) const;
  
  private:
    WeatherStation& _weatherStation;
    const std::string _outputFilename;
};

#endif  /* WEATHERLOGGER_HPP_ */