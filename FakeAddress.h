#pragma once

#include "Library.h"
using namespace std;

class FakeAddress
{
private:
    string _number;
    string _street;
    string _ward;
    string _district;
    string _city;

    vector<string> _$district;
    vector<string> _$ward;
    vector<string> _$street;

    inline static std::shared_ptr<FakeAddress> _instance = nullptr;

    FakeAddress();

public:
    static std::shared_ptr<FakeAddress> instance()
    {
        if (_instance == nullptr)
        {
            FakeAddress *temp = new FakeAddress();
            _instance = std::shared_ptr<FakeAddress>(temp);
        }

        return _instance;
    }

    string next();
};