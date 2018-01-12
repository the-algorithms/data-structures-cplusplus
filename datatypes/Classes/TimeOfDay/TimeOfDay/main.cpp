//
//  main.cpp
//  TimeOfDay
//
//  Created by Parvez Kose on 11/21/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <iostream>
#include "TimeOfDay.h"
using namespace std;

int main() {
    TimeOfDay time1(5, 30, 0);
    TimeOfDay time2;
    int loopCount;
    
    cout << "time1: ";
    time1.Write();
    cout << "time2: ";
    time2.Write();
    cout << endl;
    
    if (time1.Equal(time2))
        cout << "Times are equal" << endl;
    else
        cout << "Times are NOT equal" << endl;
    
    time2 = time1;  //set them equal
    
    cout << "time1: ";
    time1.Write();
    cout << "time2: ";
    time2.Write();
    cout << endl;
    
    if (time1.Equal(time2))
        cout << "Times are equal" << endl;
    else
        cout << "Times are NOT equal" << endl;
    
    time2.Increment();  //Increment one, print and compare
    cout << "New time2: ";
    time2.Write();
    cout << endl;
    
    if (time2.LessThan(time1))
        cout << "time3 is less than time2";
    else
        cout << "time2 is NOT less than time1" << endl;
    
    TimeOfDay time4(23, 59, 55);    //Instantiate one near the maximum
    cout << "Incrementing time1 from 23:59:55" << endl;
    for (loopCount = 1; loopCount <= 10; loopCount++){
        time4.Write();
        cout << ' ';
        time4 = time4.Increment();
    }
    cout << endl;
    return 0;
    
}
