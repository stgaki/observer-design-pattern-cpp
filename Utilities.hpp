#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include <bits/stdc++.h> 

#define MIN_TEMP (-20)
#define MAX_TEMP (+45)
#define MIN_HUMID 0
#define MAX_HUMID 100
#define MIN_PRES (25.9)
#define MAX_PRES (32.01)

namespace utils {

void setRandomSeed();
float RandomFloat(float min, float max);

// weather data generators 
float generateRandTemperature(int min=MIN_TEMP, int max=MAX_TEMP);
float generateRandHumidity(int min=MIN_HUMID, int max=MAX_HUMID);
float generateRandPressure();

void generateWeatherData(float& temp, float& humid, float& pres);

void generateSmartWeatherData(float& temp, float& humid, float& pres, bool isPressureDecreasing);

// print a simple message
void message(const char * s);
void message(const char * s, bool v);
template<typename T>
void message(const char * s, const T & v) { std::cout << s << ": " << v << std::endl; }

}

#endif //UTILITIES_HPP_