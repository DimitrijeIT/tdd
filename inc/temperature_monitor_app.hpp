#pragma once
#include "codings.hpp"
#include "temperature_reader.hpp"

#define MOCKABLE virtual
class TemperatureMonitorApp
{
public:
	TemperatureMonitorApp(Codings &codings, TemeperatureReader &temperature_reader);
	MOCKABLE int run();

private:
	Codings &codings_;
	TemeperatureReader &temperature_reader_;
};
