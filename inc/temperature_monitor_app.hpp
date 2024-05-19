#pragma once
#include "codings.hpp"
#include "temperature_reader.hpp"

class TemperatureMonitorApp
{
public:
	TemperatureMonitorApp(Codings& codings, TemeperatureReader& temperature_reader);
	int run();
	
private:
	Codings& codings_;
	TemeperatureReader& temperature_reader_;
};

