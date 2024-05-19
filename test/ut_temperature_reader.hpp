#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mock_filter.hpp"
#include "temperature_reader.hpp"

class UtTemeperatureReader: public ::testing::Test
{
	public:
	UtTemeperatureReader();
	
  protected: //todo: Exmplain why
	::testing::NiceMock<MockFilter> mock_filter_;
	TemeperatureReader temperature_reader_;
};