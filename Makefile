# WeatherStation Makefile
CC		= g++
TARGET	= WeatherStation
SRC		= main.cpp WeatherData.cpp WeatherStation.cpp CurrentWeatherReport.cpp WeatherForecastReport.cpp 

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

.PHONY: clean
clean:
	rm -f $(TARGET)