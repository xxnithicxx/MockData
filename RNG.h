#pragma once

#include <random>
#include <ctime>
#include <iostream>
#include <memory>
using namespace std;

class RNG
{
private:
    inline static std::shared_ptr<RNG> _instance = NULL;
    RNG();

public:
    static std::shared_ptr<RNG> instance()
    {
        if (_instance == NULL)
        {
            RNG *temp = new RNG();
            _instance = std::shared_ptr<RNG>(temp);
        }

        return _instance;
    }

    int next();
    int next(int min);
    int next(int min, int max);
};