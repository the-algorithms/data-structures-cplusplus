//
//  main.cpp
//  Classes
//
//  Created by Parvez Kose on 11/18/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
using namespace std;

class TimeOfDay
{
public:
    TimeOfDay();
    TimeOfDay(int initHours, int initMinutes, int initSeconds);
    TimeOfDay Increment() const;
    void Write() const;
    bool Equal(TimeOfDay otherTime) const;
    bool LessThan(TimeOfDay otherTime) const;
private:
    int hours;
    int minutes;
    int seconds;
};

// constructor 1: default
TimeOfDay::TimeOfDay()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

// constructor 2: of 3 parameters
TimeOfDay::TimeOfDay(int initHours, int initMinutes, int initSeconds)
{
    hours = initHours;
    minutes = initMinutes;
    seconds = initSeconds;
}

TimeOfDay TimeOfDay::Increment() const
{
    TimeOfDay result(hours, minutes, seconds);
    
    result.seconds++; // increment seconds
    if (result.seconds > 59) // adjust if seconds carry
    {
        result.seconds = 0;
        if (result.minutes > 59) { //adjust if minutes carry
            result.minutes = 0;
            if (result.hours > 23) { //adjust if hours carry
                result.hours = 0;
            }
        }
    }
    return result;
}

void TimeOfDay::Write() const
{
    if (hours < 10)
        cout << '0';
    cout << hours << ':';
    if (minutes < 10)
        cout << '0';
    cout << minutes << ':';
    if (seconds < 10)
        cout << '0';
    cout << seconds;
    cout << endl;
    
}

bool TimeOfDay::LessThan(TimeOfDay otherTime) const
{
    return (hours < otherTime.hours || (hours == otherTime.hours
            && minutes < otherTime.minutes) || (hours == otherTime.hours
            && minutes == otherTime.minutes
            && seconds == otherTime.seconds));
}

bool TimeOfDay::Equal(TimeOfDay otherTime) const
{
    return (hours == otherTime.hours
            && minutes == otherTime.minutes
            && seconds == otherTime.seconds);
}

void DoSomething();

int main(int argc, const char * argv[]) {
    // insert code here...
    TimeOfDay time1;
    TimeOfDay time2(17, 58, 2);
    
    time1.Write();
    time2.Write();
    
    int inputHours;
    int inputMinutes;
    int inputSeconds;
    
    TimeOfDay time3(15, 20, 0);
    
    cout << "Enter hours, minutes, seconds: ";
    cin >> inputHours >> inputMinutes >> inputSeconds;
    TimeOfDay time4(inputHours, inputMinutes, inputSeconds);
    
    if (time3.LessThan(time4)) {
        DoSomething();
    }
    time3.Write();
    time4.Write();
    time3 = time4;
    time4.Write();
    
    return 0;
}

void DoSomething() {
    cout << "so, did something" << endl;
}
