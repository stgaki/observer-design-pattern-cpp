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

void setRandomSeed(){
    srand((unsigned) time(NULL));
}

float RandomFloat(float min, float max) {
    return  (max - min) * ((((float) rand()) / (float) RAND_MAX)) + min;
}

float generateRandTemperature(int min=MIN_TEMP, int max=MAX_TEMP){
    return trunc(RandomFloat(0, max+abs(min))-abs(min));
}

float generateRandHumidity(int min=MIN_HUMID, int max=MAX_HUMID){
    return trunc(RandomFloat(min, max));
}

float generateRandPressure(){
    return RandomFloat(MIN_PRES, MAX_PRES);
}

void generateWeatherData(float& temp, float& humid, float& pres){
    temp = generateRandTemperature();
    humid = generateRandHumidity();
    pres = generateRandPressure();
}

void generateSmartWeatherData(float& temp, float& humid, float& pres, bool isPressureDecreasing){
    if(isPressureDecreasing) { 
        temp = generateRandTemperature(temp-10, temp); // temperature should be decreasing
        humid = generateRandHumidity(humid, MAX_HUMID); // humidity should be increasing
    }
    else {
        temp = generateRandTemperature(temp, temp+10); // temperature should be increasing
        humid = generateRandHumidity(MIN_HUMID, humid); // humidity should be decreasing 
    }
    pres = generateRandPressure();
}

// print a simple message
void message(const char * s) { std::cout << s << std::endl; }
void message(const char * s, bool v) { std::cout << s << ( v ? "True" : "False" ) << std::endl; }
template<typename T>
void message(const char * s, const T & v) { std::cout << s << ": " << v << std::endl; }

#endif //UTILITIES_HPP_