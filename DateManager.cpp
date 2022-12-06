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
    temporaryDate = temporaryDate + '.' +SupportMethod::convertIntToString (todayMonth);
    temporaryDate = temporaryDate + '.' +SupportMethod::convertIntToString (todayDay);
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

bool DateManager::isDateValid(int day, int month, int year)
{

    if(1000 <= year <= todayYear)
    {
        if((month==1 || month==3 || month==5|| month==7|| month==8||month==10||month==12) && day>0 && day<=31)
        {
            return 1;
        }
        else if(month==4 || month==6 || month==9|| month==11 && day>0 && day<=30)
        {
            return 1;
        }
        else if(month==2)
        {
            if((year%400==0 || (year%100!=0 && year%4==0)) && day>0 && day<=29)
            {
                return 1;
            }
            else if(day>0 && day<=28)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }

    }
    else
    {
        return 0;
    }
  return 0;
}
