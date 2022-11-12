#pragma once

#define MAX_AGE 118

#include "Library.h"
#include "RNG.h"  
using namespace std;


class FakeDoB
{
private:
    int _day;
    int _month;
    int _year;
    inline static shared_ptr<FakeDoB> _instance = nullptr;
    FakeDoB();

public:
    static shared_ptr<FakeDoB> instance()
    {
        if (_instance == nullptr)
        {
            FakeDoB *temp = new FakeDoB();
            _instance = shared_ptr<FakeDoB>(temp);
        }

        return _instance;
    }

    string next(int age);
    bool isValid(int day, int month, int year);

    static bool isLeapYear(int year);
};