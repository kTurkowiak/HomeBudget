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
    temporaryDate = temporaryDate + '-' +SupportMethod::convertIntToString (todayMonth);
    temporaryDate = temporaryDate + '-' +SupportMethod::convertIntToString (todayDay);
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
    if (todayDay >=10)
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
