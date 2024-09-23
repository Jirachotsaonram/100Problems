#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> insert_at_front(const vector<string> &words)
{
    vector<string> result;
    for (const string &word : words)
    {
        result.insert(result.begin(), word);
    }
    return result;
}

int main()
{
    vector<string> words = {"apple", "banana", "cherry"};
    vector<string> result = insert_at_front(words);
    cout << "[";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}