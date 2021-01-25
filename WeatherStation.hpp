#ifndef WEATHERSTATION_HPP_
#define WEATHERSTATION_HPP_

#include <list>
#include "SubjectItf.hpp"
#include "ObserverItf.hpp"
#include "WeatherData.hpp"

class WeatherStation: public SubjectItf {
  
  public:
    WeatherStation();
    WeatherStation(WeatherData data);
    virtual ~WeatherStation();  
  
    virtual void registerObserver(ObserverItf* observer) override;
    virtual void removeObserver(ObserverItf* observer) override;
    virtual void notifyObservers() override;
  
    void setMeasurements(WeatherData weatherData); 
    WeatherData getWeatherData() const;
    
    bool isRegistered(ObserverItf* observer) const;
    int getNumberOfObservers() const;
  
  private:
    std::list<ObserverItf*> _observers;
    WeatherData _weatherData;
};

#endif /* WEATHERSTATION_HPP_ */