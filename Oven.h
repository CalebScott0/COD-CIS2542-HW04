#ifndef OVEN_H
#define OVEN_H

class Oven
{
    public:
        Oven();
        int GetCurrentTemperature() const;
        int GetSetTemperature() const;
        void SetSetTemperature(int temperature);
        void TurnOn(int temperature = 350);
        void TurnOff();
        bool IsOn() const;
        int GetMinimumTemperature() const;
        int GetMaximumTemperature() const;
        int GetRoomTemperature() const;
        void SimulatePassingOfTime(int minutes);
        
    private:
        int currentOvenTemperature;
        int setOvenTemperature;
        bool isOvenOn;
        static const int roomTemperature;
        static const int maxOvenTemperature;
        static const int minOvenTemperature;  
        
};

#endif

