#include "RNG.h"
#include "FakeName.h"
#include "FakeID.h"
#include "FakeAddress.h"
#include "FakeTel.h"
#include "FakeEmail.h"
#include "FakeDoB.h"
#include "FakeGPA.h"
#include "Library.h"

int main()
{
    string fullName;
    ofstream nameFile("mockData.txt");

    for (int i = 0; i < 30; i++)
    {
        fullName = FakeName::instance()->next();
        nameFile << FakeID::instance()->next() << "-";
        nameFile << fullName << "-";
        nameFile << FakeAddress::instance()->next() << "-";
        nameFile << FakeEmail::instance()->next(fullName) << "-";
        nameFile << FakeTel::instance()->next() << "-";
        nameFile << FakeDoB::instance()->next(2003) << "-";
        nameFile << FakeGPA::instance()->next() << endl;
    }

    return 0;
}