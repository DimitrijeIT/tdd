#include "ut_temperature_reader.hpp"

UtTemeperatureReader::UtTemeperatureReader() : mock_filter_(),
                                               temperature_reader_(mock_filter_)
{
}