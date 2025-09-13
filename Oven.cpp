#include "Oven.h"

const int Oven::roomTemperature = 72;
const int Oven::maxOvenTemperature = 550;
const int Oven::minOvenTemperature = 200;

Oven::Oven()
    : currentOvenTemperature(roomTemperature),
      setOvenTemperature(350),
      isOvenOn(false)
{
    // Empty.
}

int Oven::GetCurrentTemperature() const
{
    return currentOvenTemperature;
}

int Oven::GetSetTemperature() const
{
    return setOvenTemperature;
}

int Oven::GetMinimumTemperature() const
{
    return minOvenTemperature;
}

int Oven::GetMaximumTemperature() const
{
    return maxOvenTemperature;
}

int Oven::GetRoomTemperature() const
{
    return roomTemperature;
}

bool Oven::IsOn() const
{
    return isOvenOn;
}

void Oven::SetSetTemperature(int temperature)
{
    if(temperature <= maxOvenTemperature && temperature >= minOvenTemperature)
    {
        setOvenTemperature = temperature;
    }
}

void Oven::TurnOn(int temperature)
{
    if(temperature <= maxOvenTemperature && temperature >= minOvenTemperature)
    {
        setOvenTemperature = temperature;
    }

    isOvenOn = true;
}

void Oven::TurnOff()
{
    isOvenOn = false;
}

void Oven::SimulatePassingOfTime(int minutes)
{
    if(isOvenOn)
    {
        for(int i = 1; i <= minutes; ++i)
        {
            if(currentOvenTemperature <= (setOvenTemperature - 25))
            {
                currentOvenTemperature += 25;
            }
            else // within 25 degrees of setOvenTempature
            {
                currentOvenTemperature = setOvenTemperature;
                break;
            }
        }
    }
    else
    {
        for(int i = 1; i <= minutes; ++i)
        {
            if(currentOvenTemperature >= (roomTemperature + 15))
            {
                currentOvenTemperature -= 15;
            }
            else // within 15 degrees F of roomTemperature
            {
                currentOvenTemperature = roomTemperature;
                break;
            }
        }
    }
}

