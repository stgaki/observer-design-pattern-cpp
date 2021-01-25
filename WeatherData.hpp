#ifndef WEATHERDATA_HPP_
#define WEATHERDATA_HPP_

class WeatherData {
    
  public:
    WeatherData(float temperature, float humidity, float pressure);
  
    void setTemperature(const float temperature); 
    void setHumidity(const float humidity);
    void setPressure(const float pressure);
    void setWeatherData(const float temperature, const float humidity, const float pressure);

    float getTemperature() const;
    float getHumidity() const;
    float getPressure() const;
  
  private:
    float _temperature;
    float _humidity;
    float _pressure;  
  
};

#endif /*WEATHERDATA_HPP_*/