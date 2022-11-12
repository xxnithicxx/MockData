#include "FakeHouseNumber.h"

FakeHouseNumber::FakeHouseNumber(){
    _number = "";
}

string FakeHouseNumber::next(){
    int alley = RNG::instance()->next(500);
    int number = RNG::instance()->next(500);
    stringstream ss;
    ss << alley << "/" << number;
    _number = ss.str();

    return _number;
}