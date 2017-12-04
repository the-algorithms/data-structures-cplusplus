//
//  DateType.h
//  DateType
//
//  Created by Parvez Kose on 11/19/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#ifndef DateType_h
#define DateType_h

class DateType {
    
public:
    void Initialize (int newMonth, int newDay, int newYear);
    int GetYear() const;    // Returns year
    int GetMonths() const;  // Returns month
    int GetDay() const; // Returns day
    
private:
    int year;
    int month;
    int day;
};


#endif /* DateType_h */
