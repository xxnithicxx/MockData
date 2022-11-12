#include "FakeTel.h"

FakeTel::FakeTel()
{
    ifstream file("Resource\\tel.txt");
    string temp;
    if (file.is_open())
    {
        getline(file, temp);
        while (getline(file, temp))
        {
            _$tel.push_back(temp);
        }
    }
}

string FakeTel::next()
{
    stringstream ss;
    ss << _$tel[RNG::instance()->next(_$tel.size() - 1)] << RNG::instance()->next(9);
    ss << " " << RNG::instance()->next(999) << " " << RNG::instance()->next(999); 

    return ss.str();
}