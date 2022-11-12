#include "FakeEmail.h"

FakeEmail::FakeEmail()
{
    // Load email
    ifstream emailFile("Resource\\email.txt");
    string temp;
    if (emailFile.is_open())
    {
        while (getline(emailFile, temp))
        {
            _$email.push_back(temp);
        }
    }
}

string FakeEmail::UTF8ToASCII(string name)
{
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring wstr = conv.from_bytes(name);

    // Using regex to replace all UTF-8 characters with ASCII characters
    wregex charA(L"[àáảạãâầấẩậẫăằắẳặẵÀÁẢẠÃÂẦẤẨẬẪĂẰẮẲẶẴ]");
    wregex charE(L"[èéẻẹẽêềếểệễÈÉẺẸẼÊỀẾỂỆỄ]");
    wregex charI(L"[ìíỉịĩÌÍỈỊĨ]");
    wregex charO(L"[òóỏọõôồốổộỗơờớởợỡÒÓỎỌÕÔỒỐỔỘỖƠỜỚỞỢỠ]");
    wregex charU(L"[ùúủụũưừứửựữÙÚỦỤŨƯỪỨỬỰỮ]");
    wregex charY(L"[ỳýỷỵỹỲÝỶỴỸ]");
    wregex charD(L"đ|Đ");

    wstr = regex_replace(wstr, charA, L"a");
    wstr = regex_replace(wstr, charE, L"e");
    wstr = regex_replace(wstr, charI, L"i");
    wstr = regex_replace(wstr, charO, L"o");
    wstr = regex_replace(wstr, charU, L"u");
    wstr = regex_replace(wstr, charY, L"y");
    wstr = regex_replace(wstr, charD, L"d");

    // Convert wstring to string
    string str(wstr.begin(), wstr.end());
    return str;
}

string FakeEmail::next(string fullName)
{
    // Get random email
    string email = _$email[RNG::instance()->next(_$email.size() - 1)];
    stringstream ss;
    string firstName, middleName, lastName;

    // Split full name into first name, middle name and last name
    ss << fullName;
    ss >> firstName >> middleName >> lastName;
    firstName = UTF8ToASCII(firstName);
    middleName = UTF8ToASCII(middleName);
    lastName = UTF8ToASCII(lastName);

    transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
    transform(middleName.begin(), middleName.end(), middleName.begin(), ::tolower);
    transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
    stringstream emailSS;
    emailSS << firstName[0] << middleName[0] << lastName << '@' << email;

    return emailSS.str();
}