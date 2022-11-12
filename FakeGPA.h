#pragma once

#include "Library.h"
#include "RNG.h"

class FakeGPA
{
private:
    int _num;
    int _frac;
    inline static shared_ptr<FakeGPA> _instance = nullptr;
    FakeGPA()
    {
        _num = 0;
        _frac = 0;
    }

public:
    static shared_ptr<FakeGPA> instance()
    {
        if (_instance == nullptr)
        {
            FakeGPA *temp = new FakeGPA();
            _instance = shared_ptr<FakeGPA>(temp);
        }

        return _instance;
    }

    string next() {
        _num = RNG::instance()->next(0, 4);
        _frac = RNG::instance()->next(0, 9);

        if (_num == 4 && _frac > 0) {
            _frac = 0;
        }

        return to_string(_num) + "." + to_string(_frac);
    }
};