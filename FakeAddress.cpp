#include "FakeAddress.h"
#include "FakeHouseNumber.h"

FakeAddress::FakeAddress()
{
    string line;
    ifstream districtFile("Resource/district.txt");
    if (districtFile.is_open())
    {
        while (getline(districtFile, line))
        {
            _$district.push_back(line);
        }
        districtFile.close();
    }

    ifstream wardFile("Resource/ward.txt");
    if (wardFile.is_open())
    {
        while (getline(wardFile, line))
        {
            _$ward.push_back(line);
        }
        wardFile.close();
    }

    ifstream streetFile("Resource/street.txt");
    if (streetFile.is_open())
    {
        while (getline(streetFile, line))
        {
            _$street.push_back(line);
        }
        streetFile.close();
    }
}

string FakeAddress::next()
{
    stringstream ss;
    ss << FakeHouseNumber::instance()->next() << " " << _$street[RNG::instance()->next(_$street.size())] << ", " << _$ward[RNG::instance()->next(_$ward.size())] << ", " << _$district[RNG::instance()->next(_$district.size())] << ", HCM City";

    return ss.str();
}
