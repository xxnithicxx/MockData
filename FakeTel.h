#pragma once

#include "Library.h"
using namespace std;

class FakeTel
{
private:
    string _tel;
    vector<string> _$tel;
    inline static shared_ptr<FakeTel> _instance = nullptr;
    FakeTel();

public:
    static shared_ptr<FakeTel> instance()
    {
        if (_instance == nullptr)
        {
            FakeTel *temp = new FakeTel();
            _instance = shared_ptr<FakeTel>(temp);
        }

        return _instance;
    }

    string next();
};
