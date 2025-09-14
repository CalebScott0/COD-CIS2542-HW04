#include "Oven.h"


Oven::Oven()
    : currentTemperature(72),
      setTemperature(350),
      isOvenOn(false),
      roomTemperature(72),
      maxTemperature(550),
      minTemperature(200)
{
    // Empty.
}

int Oven::GetCurrentTemperature() const
{
    return currentTemperature;
}

int Oven::GetSetTemperature() const
{
    return setTemperature;
}

int Oven::GetMinimumTemperature() const
{
    return minTemperature;
}

int Oven::GetMaximumTemperature() const
{
    return maxTemperature;
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
    if(temperature <= maxTemperature && temperature >= minTemperature)
    {
        setTemperature = temperature;
    }
}

void Oven::TurnOn(int temperature)
{
    isOvenOn = true;
    SetSetTemperature(temperature);
}

void Oven::TurnOff()
{
    isOvenOn = false;
}

void Oven::SimulatePassingOfTime(int minutes)
{
    if(isOvenOn)
    {
        if(currentTemperature < setTemperature)
        {
            currentTemperature += (25 * minutes);
            if(currentTemperature > setTemperature)
            {
                currentTemperature = setTemperature;
            }
        }            
        else
        {
            currentTemperature -= (15 * minutes);
            if(currentTemperature < setTemperature)
            {
                currentTemperature = setTemperature;
            }
        }

    }
    else
    {
        currentTemperature -= (15 * minutes);
        if(currentTemperature < roomTemperature)
        {
            currentTemperature = roomTemperature;
        }
    }
}

