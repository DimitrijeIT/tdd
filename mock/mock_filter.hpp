#pragma once

#include <gmock/gmock.h>
#include "filter.hpp"

class MockFilter : public Filter
{
public:
	MockFilter() = default;
	~MockFilter() = default;

	MOCK_METHOD(int, GetMedian, (), (override));
	MOCK_METHOD(int, GetFilterdData, (int), (override));
};
