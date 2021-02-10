# Observer Design Pattern in C++

## Observer Design Pattern 
Defines an ***1-Subject*** to ***many-Observers*** relationship between objects, such that when Subject object changes state, all its Obervers are notified and updated automatically.

## When to use
Whenever you have objects that want to be notified when another object's state is changed.

## Benefits
You can loosely couple objects together. An object can broadcast changes in state to registered observers without the need to know about observer's implementation details.

## Use Case: Weather Station

Imagine that you have a Weather Station object which keeps measurement data that gets from sensors like temperature, humidity and pressure. 

Every time Weather Station gets new data from the sensors, observers like CurrentWeatherReport, ExtremeTemperatureAlert and WeatherDataLogger that are interested in these data, they get notified and take actions like displaying the new weather report or displaying an alert in case temperature is getting too high or low.  

The design allows Observers to easily be registered and unregistered for notifications of the WeatherStation.
So new Observers like WeatherForecastReport or HighHumidityAlert can easily be added and current Observers like WeatherDataLogger can easily be removed.

## Input/Output

###Input

Incoming Weather Data are needed to run the project.

This data would normally be coming from censors reading, but that's not available for purposes of this project.

For that a ***weather data generator*** is provided that randomly generates weather data within some logical ranges e.g. Humidity values between 0% and 100%. 

The randomizer can be found in Utilities class. Here is an example:

'''
utils::generateWeatherData(temp, humid, pres);
'''

# Output 

Depending on the kind of Observers that have been registered to Weather Station Subject and the incoming weather data, a current and/or forecast weather report will be displayed, an alarm if current temperature is too low or too high and incoming weather data will be logged in "weather.log" file.

Output example:
'''
Current Conditions: 38 degrees Celcius, 71% humidity, 28.5257 atm barometric pressure

EXTREME TEMPERATURE ALARM: Beware for extreme heat!

Forecast: Improving weather on the way!

Current Conditions: 29 degrees Celcius, 42% humidity, 30.9482 atm barometric pressure

Forecast: Improving weather on the way!
'''

## UML Class Diagram
The class diagram of the solution design can be found in "class diagram solution design.PNG".


