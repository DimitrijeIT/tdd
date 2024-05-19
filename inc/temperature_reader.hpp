#pragma once

#include "filter.hpp"

#define MOCKABLE virtual
class TemeperatureReader
{
public:
	TemeperatureReader(Filter &filter);
	MOCKABLE int ReadRawTemperature();
	MOCKABLE int ReadFilterdTemperature();

	// todo: PRIVATE:
	MOCKABLE int CelsiusToKelvin(int temp_in_celsius);
	MOCKABLE int KelvinToCelsius(int temp_in_kelvin);

	Filter &filter_;
};