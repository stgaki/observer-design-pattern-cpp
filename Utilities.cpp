#include "Utilities.hpp"

void utils::setRandomSeed(){
    srand((unsigned) time(NULL));
}

float utils::RandomFloat(float min, float max) {
    return  (max - min) * ((((float) rand()) / (float) RAND_MAX)) + min;
}

float utils::generateRandTemperature(int min, int max) {
    return trunc(RandomFloat(0, max+abs(min))-abs(min));
}

float utils::generateRandHumidity(int min, int max) {
    return trunc(RandomFloat(min, max));
}

float utils::generateRandPressure(){
    return RandomFloat(MIN_PRES, MAX_PRES);
}

void utils::generateWeatherData(float& temp, float& humid, float& pres) {
    temp = generateRandTemperature();
    humid = generateRandHumidity();
    pres = generateRandPressure();
}

void utils::generateSmartWeatherData(float& temp, float& humid, float& pres, bool isPressureDecreasing) {
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

void utils::message(const char * s) { std::cout << s << std::endl; }
void utils::message(const char * s, bool v) { std::cout << s << ( v ? "YES" : "NO" ) << std::endl; }