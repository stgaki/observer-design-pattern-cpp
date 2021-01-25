# WeatherStation
 The weatherStation implements the Observer Design Pattern.
 The subject is the WeatherStation which keeps measurement data that takes from censors like temperature, humidity and pressure.
 The observers like UserInterface, Logger and Alert are all interested in these data and they get notified when WeatherStation gets new data from the censors.
 The design allows for Observers to easily be registed and unregirested for notifications of the WeatherStation. 


