//
//  DateType.cpp
//  DateType
//
//  Created by Parvez Kose on 11/19/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <stdio.h>

#include "DateType.h"   // Gain access to specification of class

void DateType::Initialize
(int newMonth, int newDay, int newYear)
// Post: year is set to newYear
//       month is set to newMonth
//      day is set to newDay
{
    year = newYear;
    month = newMonth;
    day = newDay;
}

int DateType::GetMonths() const
// Accesssor function to data member month
{
    return month;
}

int DateType::GetYear() const
// Accessor function for data member year
{
    return year;
}

int DateType::GetDay() const
// Accessor function for data member day
{
    return day;
}
