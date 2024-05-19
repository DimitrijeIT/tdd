#include "temperature_monitor_app.hpp"

TemperatureMonitorApp::TemperatureMonitorApp(Codings &codings, TemeperatureReader &temperature_reader):
    codings_(codings),
    temperature_reader_(temperature_reader)
{
}

int TemperatureMonitorApp::run()
{
    int i = codings_.ConvertCentigradeToCelsius(1);
    int a = temperature_reader_.ReadRawTemperature();
    return a;
}