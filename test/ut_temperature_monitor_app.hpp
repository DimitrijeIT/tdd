#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mock_codings.hpp"
#include "mock_temperature_reader.hpp"
#include "temperature_monitor_app.hpp"
#include "mock_filter.hpp"
class UtTemperatureMonitorApp : public ::testing::Test
{
public:
    UtTemperatureMonitorApp();

public:
    ::testing::NiceMock<MockCodings> mock_codings_;
    ::testing::NiceMock<MockFilter> mock_filter;
    ::testing::NiceMock<MockTemeperatureReader> mock_temperature_reader_;

    TemperatureMonitorApp temperature_monitor_app_;
};
