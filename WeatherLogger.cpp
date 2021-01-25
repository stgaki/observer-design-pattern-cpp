#include <iostream>
#include <fstream>
#include <sstream>
#include "WeatherLogger.hpp"

WeatherLogger::WeatherLogger(WeatherStation& weatherStation, std::string outputFilename):
  _weatherStation(weatherStation),
  _outputFilename(outputFilename){ 
  _weatherStation.registerObserver(this);
  logToFile(_weatherStation.getWeatherData()); //log weather data as soon as you register!
}

WeatherLogger::~WeatherLogger(){
    _weatherStation.removeObserver(this); 
}

void WeatherLogger::update(WeatherData data){
    logToFile(data);
}

void WeatherLogger::registerToStation(){
    _weatherStation.registerObserver(this);
}

void WeatherLogger::unregisterFromStation(){
    _weatherStation.removeObserver(this);
}

void WeatherLogger::logToFile(WeatherData data) const{
    std::ofstream outputFile;
    outputFile.open(_outputFilename.c_str(), std::ios_base::app);
    if (!outputFile.good()) std::cout << "Unable to open output file: " << _outputFilename << std::endl;
    outputFile << data.getTemperature() << " " << data.getHumidity() << " " << data.getPressure() << std::endl;
    outputFile.close();
}
  