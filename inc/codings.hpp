#pragma once

#define MOCKABLE virtual //todo: Vidi sta da radimo sa ovim?? Da li da definismo u cmake.


/*
    #ifdef LUM_MOCK_ENABLE
    #define MOCKABLE virtual
    #else
    #define MOCKABLE
    #endif
*/

class Codings
{
public:
	MOCKABLE int GetMinThreshold();
	MOCKABLE int GetMaxThreshold();
	
	MOCKABLE int ConvertCentigradeToCelsius(int temp_in_centigrade);
};