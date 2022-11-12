#include "FakeName.h"

FakeName::FakeName()
{
    // Load first names
    ifstream firstNamesFile("Resource\\firstnames.txt");
    string temp, name;
    if (firstNamesFile.is_open())
    {
        while (getline(firstNamesFile, temp))
        {
            _$firstNames.push_back(temp);
        }
    }

    // Load middle names
    ifstream middleNamesFile("Resource\\middlenames.txt");
    if (middleNamesFile.is_open())
    {
        while (getline(middleNamesFile, temp))
        {
            stringstream ss(temp);
            int sex = 0;
            getline(ss, temp, ',');
            name = temp;
            getline(ss, temp);
            if (temp == "Male")
                sex = MALE;
            else if (temp == "Female")
                sex = FEMALE;
            else
                sex = BOTH;
            _$middleNames.push_back(make_pair(name, sex));
        }
    }

    // Load last names
    ifstream lastNamesFile("Resource\\lastnames.txt");
    if (lastNamesFile.is_open())
    {
        while (getline(lastNamesFile, temp))
        {
            stringstream ss(temp);
            int sex = 0;
            getline(ss, temp, ',');
            name = temp;
            getline(ss, temp);
            if (temp == "Male")
                sex = MALE;
            else if (temp == "Female")
                sex = FEMALE;
            else
                sex = BOTH;
            _$lastNames.push_back(make_pair(name, sex));
        }
    }
}

string FakeName::getFirstName()
{
    return _$firstNames[RNG::instance()->next(_$firstNames.size())];
}

string FakeName::getMiddleName(int sex)
{
    pair<string, int> result;
    do
    {
        result = _$middleNames[RNG::instance()->next(_$middleNames.size())];
    } while (!(result.second & sex));
    return result.first;
}

string FakeName::getLastName(int sex)
{
    pair<string, int> result;
    do
    {
        result = _$lastNames[RNG::instance()->next(_$lastNames.size())];
    } while (!(result.second & sex));
    return result.first;
}

string FakeName::next()
{
    _firstName = getFirstName();
    int sex = RNG::instance()->next(3);
    if (sex == 0)
        sex = MALE;
    else if (sex == 1)
        sex = FEMALE;
    else
        sex = BOTH;

    _middleName = getMiddleName(sex);
    _lastName = getLastName(sex);

    string result = _firstName + " " + _middleName + " " + _lastName;

    return result;
}