#include <iostream>
#include <string>
using namespace std;

string replace_strings(string &s);

int main()
{
    string input;
    cout << "Input : ";
    getline(cin, input);
    string replace = replace_strings(input);
    cout << "Output : " << replace;
}

string replace_strings(string &s)
{
    string result = s;

    for (char &c : result)
    {
        if (c == 'a' || c == 'A')
        {
            c = '@';
        }
        if (c == 'l' || c == 'L')
        {
            c = '1';
        }
        if (c == 'o' || c == 'O')
        {
            c = '0';
        }
    }
    return result;
}