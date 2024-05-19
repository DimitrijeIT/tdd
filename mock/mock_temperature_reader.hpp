#pragma once
#include <gmock/gmock.h>
#include "temperature_reader.hpp"
#include "mock_filter.hpp"

class MockTemeperatureReader: public TemeperatureReader
{
    public:
    MockTemeperatureReader(MockFilter& mock_filter): TemeperatureReader(mock_filter)
    {}
	MOCK_METHOD(int, ReadRawTemperature, (), (override));
	MOCK_METHOD(int, ReadFilterdTemperature, (), (override));
	MOCK_METHOD(int, CelsiusToKelvin, (int), (override));
	MOCK_METHOD(int, KelvinToCelsius, (int), (override));		
};