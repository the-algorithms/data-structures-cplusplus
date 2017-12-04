//***************************************************
// IMPLEMENTATION FILE (TimeOfDay.cpp)
// This file implements the TimeOfDay member function
//
// Constructors:
// Transformers:
// Observers: Increment, Write, Equal, LessThan;
// Observers do not modify the private data of class
// Because its declared as const; compiler prevents these
// functions from assigning new values to the private data
//
//***************************************************

#include <iostream>
using namespace std;
#include "TimeOfDay.h"

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
    // create a duplicate of instance and increment duplicate
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

void TimeOfDay::Write() const
{
    // Inser extra 0 if there is only one digit in a place
    if(hours < 10)
        cout << '0';
    cout << hours << ':';
    if (minutes < 10)
        cout << '0';
    cout << minutes << ':';
    if (seconds < 10)
        cout << '0';
    cout << seconds;
}

//***************************************************

bool TimeOfDay::Equal(TimeOfDay otherTime) const
{
    return (hours == otherTime.hours
            && minutes == otherTime.minutes
            && seconds == otherTime.seconds);
}

//***************************************************

bool TimeOfDay::LessThan(TimeOfDay otherTime) const
{
    return (hours < otherTime.hours || (hours == otherTime.hours && minutes < otherTime.minutes) || (hours == otherTime.hours
            && minutes == otherTime.minutes
            && seconds == otherTime.seconds));
}












