#pragma once

#define MALE 0x01
#define FEMALE 0x10
#define BOTH 0x11

#include "Library.h"
using namespace std;

// Singleton class
class FakeName
{
private:
    string _firstName;
    string _middleName;
    string _lastName;
    vector<string> _$firstNames;
    vector<pair<string, int>> _$middleNames;
    vector<pair<string, int>> _$lastNames;
    inline static shared_ptr<FakeName> _instance = nullptr;
    FakeName();

public:
    string getFirstName();
    string getMiddleName(int);
    string getLastName(int);

public:
    string next();

    static shared_ptr<FakeName> instance()
    {
        if (_instance == nullptr)
        {
            FakeName *temp = new FakeName();
            _instance = shared_ptr<FakeName>(temp);
        }

        return _instance;
    }
};
