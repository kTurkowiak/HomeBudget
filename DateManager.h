#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <string>
#include <ctime>

#include "SupportMethod.h"

using namespace std;

class DateManager
{
    int todayYear;
    int todayMonth;
    int todayDay;

    void setTodayDate();

public:
    DateManager ()
    {
        setTodayDate();
    };
    int getTodayYear();
    int getTodayMonth();
    int getTodayDay();
    string getTotalTodayDateAsString();
    int getFullTodayDateAsOneNumber();
    bool isDateValid(int day, int month, int year);
    int getFirstDayOfCurrentMonth();
    int getFirstDayOfPreviousMonth();

};




#endif
