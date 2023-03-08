## STS21 Sensirion Temperature Sensor Library for Arduino

This is an Arduino library for the STS21 Sensirion temperature sensor.

## Installation

To use this library, download the STS21 folder and copy it to the libraries directory in your Arduino sketchbook folder.

## Usage

To use the STS21 library, include the STS21.h header file in your Arduino sketch:

#include <STS21.h>

Then create an instance of the STS21 class:

STS21 sensor;

You can then use the readTemperatureC() method to read the temperature in Celsius from the sensor:

float temperature = sensor.readTemperatureC();

For more information on using the STS21 library, see the example sketch included with the library.

## License

This library is released under the MIT License.