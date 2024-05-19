#include "gtest/gtest.h"

#include "ut_temperature_monitor_app.hpp"

const int kDefaultValueForTemperature = 44;

TEST_F(UtTemperatureMonitorApp, WhenThen)
{
	EXPECT_CALL(mock_codings_, ConvertCentigradeToCelsius(1));

	ON_CALL(mock_temperature_reader_, ReadRawTemperature).WillByDefault(testing::Return(kDefaultValueForTemperature));

	auto return_value = temperature_monitor_app_.run();
	EXPECT_EQ(return_value, kDefaultValueForTemperature);
}
