#pragma once

#include "Library.h"
using namespace std;

class FakeEmail
{
private:
    vector<string> _$email;
    inline static shared_ptr<FakeEmail> _instance = nullptr;
    FakeEmail();
    string UTF8ToASCII(string str);

public:
    static shared_ptr<FakeEmail> instance()
    {
        if (_instance == nullptr)
        {
            FakeEmail *temp = new FakeEmail();
            _instance = shared_ptr<FakeEmail>(temp);
        }

        return _instance;
    }

    string next(string fullName);
};
