#include "RNG.h"

int RNG::next()
{
    int result = rand();
    return result;
}

int RNG::next(int max)
{
    int result = rand() % max;
    return result;
}

int RNG::next(int min, int max)
{
    int result = rand() % (max - min + 1) + min;
    return result;
}

RNG::RNG()
{
    // Start random number generator
    srand(time(nullptr));
}
