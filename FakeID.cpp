#include "FakeID.h"

FakeID::FakeID()
{
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    _year = 1900 + ltm->tm_year;
}

string FakeID::next(Faculty faculty, Program program)
{
    stringstream id;

    int course = RNG::instance()->next(_year - 4, _year) % 100;

    // Generate a random ID
    id << course << faculty << program << RNG::instance()->next(9999);

    // Check if the ID is unique
    if (_usedIDs.find(id.str()) != _usedIDs.end())
        return next();
    else
    {
        _usedIDs.insert(id.str());
    }

    return id.str();
}

string FakeID::next(Faculty faculty)
{
    stringstream id;

    int course = RNG::instance()->next(_year - 4, _year) % 100;
    int program = RNG::instance()->next(1, 5);

    // Generate a random ID
    id << course << faculty << program << RNG::instance()->next(9999);

    // Check if the ID is unique
    if (_usedIDs.find(id.str()) != _usedIDs.end())
        return next();
    else
    {
        _usedIDs.insert(id.str());
    }

    return id.str();
}

string FakeID::next()
{
    stringstream id;

    int faculty = RNG::instance()->next(1, 7);
    int course = RNG::instance()->next(_year - 4, _year) % 100;
    int program = RNG::instance()->next(1, 5);

    // Generate a random ID
    id << course << faculty << program << RNG::instance()->next(9999);

    // Check if the ID is unique
    if (_usedIDs.find(id.str()) != _usedIDs.end())
        return next();
    else
    {
        _usedIDs.insert(id.str());
    }

    return id.str();
}
