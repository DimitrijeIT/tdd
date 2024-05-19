#include "ut_temperature_monitor_app.hpp"

UtTemperatureMonitorApp::UtTemperatureMonitorApp():
    mock_codings_(),
    mock_filter(),
    mock_temperature_reader_(mock_filter), 
    temperature_monitor_app_(mock_codings_, mock_temperature_reader_)
{
}