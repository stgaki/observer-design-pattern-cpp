#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include <bits/stdc++.h> 

#define MIN_TEMP (-20)
#define MAX_TEMP (+45)
#define MIN_PRES (25.9)
#define MAX_PRES (32.01)

void setRandomSeed(){
    srand((unsigned) time(NULL));
}

float RandomFloat(float min, float max) {
    /*const float range = max - min;
    std::cout << "range = " << range << std::endl;
    float random = range * ((((float) rand()) / (float) RAND_MAX)) + min ;
    return random;*/
    return  (max - min) * ((((float) rand()) / (float) RAND_MAX)) + min;
}

float generateRandTemperature(int min=MIN_TEMP, int max=MAX_TEMP){
    return trunc(RandomFloat(0, max+abs(min))-abs(min));
}

float generateRandHumidity(){
    return trunc(RandomFloat(0,100));
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
    //TODO
    //input old data //output new data
    //bool true: reduce temperature
    //else: increase temperature
}

// print a simple message
void message(const char * s) { std::cout << s << std::endl; }
void message(const char * s, bool v) { std::cout << s << ( v ? "True" : "False" ) << std::endl; }
template<typename T>
void message(const char * s, const T & v) { std::cout << s << ": " << v << std::endl; }

#endif //UTILITIES_HPP_