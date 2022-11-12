#include "FakeDoB.h"

FakeDoB::FakeDoB()
{
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    _day = ltm->tm_mday;
    _month = ltm->tm_mon + 1;
    _year = ltm->tm_year + 1900;
}

string FakeDoB::next(int year)
{
    if (year < _year - MAX_AGE)
    {
        return "Invalid age";
    }

    int day, month;
    int maxDaysInMonth[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
Random_Date:
    month = RNG::instance()->next(12);

    if (month == 2 && isLeapYear(year))
    {
        day = RNG::instance()->next(29);
    }
    else
    {
        day = RNG::instance()->next(maxDaysInMonth[month]);
    }

    if (!isValid(day, month, year))
    {
        goto Random_Date;
    }

    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

bool FakeDoB::isLeapYear(int year)
{
    bool result = (year % 400) || ((year % 4 == 0) && (year % 100 != 0));
    return result;
}

bool FakeDoB::isValid(int day, int month, int year)
{
    bool result = false;
    if (year == _year)
    {
        if (month == _month)
        {
            if (day <= _day)
            {
                result = true;
            }
        }
        else if (month < _month)
        {
            result = true;
        }
    }
    else if (year < _year)
    {
        result = true;
    }

    return result;
}