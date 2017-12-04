
//***************************************************
// SPECIFICATION FILE (TimeOfDay.h)
// This file gives the specifcation
// of a TimeDay abstract data type (ADT)
//***************************************************

#ifndef TimeOfDay_h
#define TimeOfDay_h

class TimeOfDay
{
public:
    // Constructors
    TimeOfDay();
    // Post: hours, minutes, and seconds have been set to 0
    TimeOfDay(int initHours, int initMinutes, int initSeconds);
    //Pre: 0 <= hours ,+ 23, 0 <= minutes <= 59, 0 <= seconds <= 59
    //Post: TimeOfDay is set according to the incoming parameters
    
    TimeOfDay Increment() const;
    // Post: Returns a TimeOfDay that is the instance plus one.
    // 23:59:59 wrapping around to 0:0:0
    
    void Write() const;
    //Post Instance has been output in the form HH:MM:SS
    
    bool Equal(TimeOfDay otherTime) const;
    // Post: Returns true if this instance equals otherTime
    // false otherwise
    
    bool LessThan(TimeOfDay otherTime) const;
    // Post: Returns true if this instance comes earlier than
    // othertime, false otherwise
private:
    int hours;
    int minutes;
    int seconds;
};

#endif /* TimeOfDay_h */
