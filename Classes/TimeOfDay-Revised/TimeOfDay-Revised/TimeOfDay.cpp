//***************************************************
// IMPLEMENTATION FILE (TimeOfDay.cpp)
// This file implements the TimeOfDay member function
//***************************************************

#include <iostream>
#include "TimeOfDay.hpp"

using namespace std;

TimeOfDay::TimeOfDay()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

//***************************************************

TimeOfDay::TimeOfDay(int initHours, int initMinutes, int initSeconds)
{
    hours = initHours;
    minutes = initMinutes;
    seconds = initSeconds;
}

//***************************************************

TimeOfDay TimeOfDay::Increment() const
{
    // Create a duplicate of instance and increment duplicate
    TimeOfDay result(hours, minutes, seconds);
    result.seconds = result.seconds++;
    
    if (result.seconds > 59) {
        result.seconds = 0;
        result.minutes = result.minutes++;
        if (result.minutes > 59) {
            result.minutes = 0;
            result.hours = result.hours++;
            if(result.hours > 23)
                result.hours = 0;
        }
    }
    return result;
}

//***************************************************

int TimeOfDay::GetHours() const
{ return hours; }

int TimeOfDay::GetMinutes() const
{ return minutes; }

int TimeOfDay::GetSeconds() const
{ return seconds }


