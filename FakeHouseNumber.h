#pragma once

#include "Library.h"
using namespace std;

class FakeHouseNumber
{
private:
    string _number;
    inline static std::shared_ptr<FakeHouseNumber> _instance = nullptr;
    FakeHouseNumber();

public:
    static std::shared_ptr<FakeHouseNumber> instance()
    {
        if (_instance == nullptr)
        {
            FakeHouseNumber *temp = new FakeHouseNumber();
            _instance = std::shared_ptr<FakeHouseNumber>(temp);
        }

        return _instance;
    }

    string next();
};