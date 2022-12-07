#include "DateManager.h"

void DateManager::setTodayDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    todayYear = 1900 + ltm->tm_year;
    todayMonth = 1 + ltm->tm_mon;
    todayDay = ltm->tm_mday;
}

int DateManager::getTodayYear()
{
    return todayYear;
}

int DateManager::getTodayMonth()
{
    return todayMonth;
}

int DateManager::getTodayDay()
{
    return todayDay;
}

string DateManager::getTotalTodayDateAsString()
{
    string temporaryDate;
    temporaryDate = SupportMethod::convertIntToString (todayYear);
    temporaryDate = temporaryDate + '-' + SupportMethod::convertIntToString (todayMonth);
    temporaryDate = temporaryDate + '-' + SupportMethod::convertIntToString (todayDay);
    return temporaryDate;
}

int DateManager::getFullTodayDateAsOneNumber()
{
    string temporaryDate, temporaryDay, temporaryMonth;
    int temporaryInt;
    temporaryDate = SupportMethod::convertIntToString(todayYear);
    if (todayMonth >= 10)
    {
        temporaryMonth = SupportMethod::convertIntToString (todayMonth);
    }
    else
    {
        temporaryMonth = '0' + SupportMethod::convertIntToString (todayMonth);
    }
    temporaryDate = temporaryDate + temporaryMonth;
    if (todayDay >= 10)
    {
        temporaryDay = SupportMethod::convertIntToString (todayDay);
    }
    else
    {
        temporaryDay = '0' + SupportMethod::convertIntToString (todayDay);
    }
    temporaryDate = temporaryDate + temporaryDay;
    temporaryInt = SupportMethod::convertStringToInt(temporaryDate);
    return temporaryInt;
}

bool DateManager::isDateValid(int day, int month, int year)
{
    if ((1000 <= year) && (year <= todayYear))
    {
        switch (month)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day <= 31)
            {
                return true;
            }
            break;
        case 4: case 6: case 9: case 11:
            if (day <= 30)
            {
                return true;
            }
            break;
        case 2:
            if ((year%400 == 0 || (year%100 != 0 && year%4 == 0)) && day > 0 && day <= 29)
            {
                return true;
            }
            else if(day > 0 && day <= 28)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        default:
            return false;
            break;
        }
    }
    return false;
}

int DateManager::getFirstDayOfCurrentMonth()
{
    int firstDayOfCurrentMonth = 0;
    string temporaryDate ="";
    temporaryDate = SupportMethod::convertIntToString (todayYear);
    if (todayMonth <10)
    {
        temporaryDate = temporaryDate + '0' + SupportMethod::convertIntToString (todayMonth);
    }
    else
    {
        temporaryDate = temporaryDate + SupportMethod::convertIntToString (todayMonth);
    }
    temporaryDate = temporaryDate + ('0') + SupportMethod::convertIntToString (1);
    firstDayOfCurrentMonth = SupportMethod::convertStringToInt(temporaryDate);
    return firstDayOfCurrentMonth;
}

int DateManager::getFirstDayOfPreviousMonth()
{
    int firstDayOfPreviousMonth = 0, previousMonth = 0;
    string temporaryDate ="";
    temporaryDate = SupportMethod::convertIntToString (todayYear);
    if ((todayMonth < 11) && (todayMonth > 1))
    {
        previousMonth = todayMonth - 1;
        temporaryDate = temporaryDate + '0' + SupportMethod::convertIntToString (previousMonth);
    }
    else if (todayMonth >= 11)
    {
        temporaryDate = temporaryDate + SupportMethod::convertIntToString (todayMonth-1);
    }
    else
    {
        temporaryDate = SupportMethod::convertIntToString (todayYear-1) + SupportMethod::convertIntToString (12);
    }
    temporaryDate = temporaryDate + ('0') + SupportMethod::convertIntToString (1);
    firstDayOfPreviousMonth = SupportMethod::convertStringToInt(temporaryDate);
    return firstDayOfPreviousMonth;
}

