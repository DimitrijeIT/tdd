#pragma once

#define MOCKABLE virtual
class Filter
{
public:
    Filter() = default;

    MOCKABLE bool PutTemperature(int temp);
    MOCKABLE int GetMedian();
    MOCKABLE int GetFilterdData(int);

private:
    int last_temp; // todo: Add array
};
