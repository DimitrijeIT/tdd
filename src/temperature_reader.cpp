#include "temperature_reader.hpp"

TemeperatureReader::TemeperatureReader(Filter &filter): filter_(filter)
{
}

int TemeperatureReader::ReadRawTemperature()
{
    return 0;
}

int TemeperatureReader::ReadFilterdTemperature()
{
    return filter_.GetFilterdData(1);
}

int TemeperatureReader::CelsiusToKelvin(int temp_in_celsius)
{
    return 0;
}

int TemeperatureReader::KelvinToCelsius(int temp_in_kelvin)
{
    return 0;
}
