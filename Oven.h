#ifndef OVEN_H
#define OVEN_H

class Oven
{
    public:
        Oven();

        int GetCurrentTemperature() const;
        int GetMaximumTemperature() const;
        int GetMinimumTemperature() const;
        int GetRoomTemperature() const;
        int GetSetTemperature() const;
        bool IsOn() const;

        void SetSetTemperature(int temperature);
        void SimulatePassingOfTime(int minutes);
        
        void TurnOff();
        void TurnOn(int temperature = 350);
        
    private:
        int currentTemperature;
        int setTemperature;
        bool isOvenOn;

        // TODO: is it bad to have these in mem as static?
        static const int roomTemperature;
        static const int maxTemperature;
        static const int minTemperature;  
};

#endif

