#include <iostream>
#include <string>
using namespace std;

bool contains_vowel(const string &s);

int main()
{
    string input;
    cout << "input : ";
    getline(cin, input);
    if (contains_vowel(input))
    {
        cout << "Vowel Presenc: True";
    }
    else
        cout << "Vowle Presenc: False";
}

bool contains_vowel(const string &s)
{
    string vowel = "aeiou";

    for (char c : s)
    {
        if (vowel.find(c) != string::npos)
        {
            return true;
        }
    }
    return false;
}