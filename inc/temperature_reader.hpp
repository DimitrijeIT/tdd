#pragma once

#include "filter.hpp"

class TemeperatureReader
{
public:
        TemeperatureReader(Filter& filter);
		int ReadRawTemperature();
		int ReadFilterdTemperature();
		
private: //todo: PRIVATE:
	int CelsiusToKelvin(int temp_in_celsius);
	int KelvinToCelsius(int temp_in_kelvin);
	
	Filter& filter_;
};