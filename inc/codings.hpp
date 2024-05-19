#pragma once

#define MOCKABLE virtual

class Codings
{
public:
	MOCKABLE int GetMinThreshold();
	MOCKABLE int GetMaxThreshold();
	
	MOCKABLE int ConvertCentigradeToCelsius(int temp_in_centigrade);
};