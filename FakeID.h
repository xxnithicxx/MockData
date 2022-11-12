#pragma once

#include "Library.h"
using namespace std;

enum Faculty
{
    Information_Technology = 1,
    Chemistry = 2,
    Physics = 3,
    Mathematics = 4,
    Biology = 5,
    Geography = 6,
    Atomic_Energy = 7,
};

enum Program
{
    DT = 1,
    VP = 2,
    CNTN = 3,
    APCS = 4,
    CLC = 5,
};

class FakeID
{
private:
    int _year;
    set<string> _usedIDs;
    inline static shared_ptr<FakeID> _instance = nullptr;
    FakeID();

public:
    static std::shared_ptr<FakeID> instance()
    {
        if (_instance == nullptr)
        {
            FakeID *temp = new FakeID();
            _instance = std::shared_ptr<FakeID>(temp);
        }

        return _instance;
    }

    string next(Faculty faculty, Program program);
    string next(Faculty faculty);
    string next();
};
