#pragma once
#include <gmock/gmock.h>
#include "codings.hpp"

class MockCodings: public Codings
{
public:
	MOCK_METHOD(int, GetMinThreshold, (), (override));
	MOCK_METHOD(int, GetMaxThreshold, (), (override));
	MOCK_METHOD(int, ConvertCentigradeToCelsius, (int), (override));

};