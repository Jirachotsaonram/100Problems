#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> collect_unique_words()
{
    vector<string> unique_word;
    string word;
    while (unique_word.size() < 5)
    {
        cout << "Input : ";
        getline(cin, word);
        if (find(unique_word.begin(), unique_word.end(), word) == unique_word.end())
        {
            unique_word.push_back(word);
        }
    }
    return unique_word;
}

int main()
{
    vector<string> unique_word = collect_unique_words();
    cout << "Output List : [";
    for (const string &word : unique_word)
    {
        cout << " \""<< word << "\" ";
    }
    cout << "]";
}