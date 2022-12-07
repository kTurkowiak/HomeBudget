#include "SupportMethod.h"

char SupportMethod::loadChar()
{
    string input = "";
    char character = {0};
    while (true)
    {
        cin.sync();
        getline(cin, input);
        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string SupportMethod::loadLine()
{
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

string SupportMethod::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupportMethod::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

string SupportMethod::convertFloatToString (float number)
{
    ostringstream ss;
    ss << number;
    string s(ss.str());
    return s;
}

float SupportMethod::convertStringToFloat (string number)
{
    float floatNumber;
    floatNumber = stof(number);
    return floatNumber;
}
