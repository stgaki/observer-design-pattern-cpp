# WeatherStation Makefile
CC		= g++
TARGET	= WeatherStation
SRC		= *.cpp 

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

.PHONY: clean
clean:
	rm -f $(TARGET)