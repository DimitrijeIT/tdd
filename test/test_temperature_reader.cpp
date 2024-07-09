#include "gtest/gtest.h"

#include "ut_temperature_reader.hpp"

const int kDefaultValueForTemperature = 33;

TEST_F(UtTemeperatureReader, WhenThen)
{
	ON_CALL(mock_filter_, GetFilterdData).WillByDefault(testing::Return(kDefaultValueForTemperature));

	auto return_value = temperature_reader_.ReadFilterdTemperature();
	EXPECT_EQ(return_value, kDefaultValueForTemperature);
}