#ifndef MOCK_FILTER
#define MOCK_FILTER

#include <gmock/gmock.h>
#include "filter.hpp"

class MockFilter: public Filter
{
public:
	MOCK_METHOD(int, GetMedian, (), (override));
	MOCK_METHOD(int, GetFilterdData, (int), (override));
};

#endif