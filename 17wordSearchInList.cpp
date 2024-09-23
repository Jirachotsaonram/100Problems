#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool is_word_in_list(const vector<string>& word_list,const string& search_term){
    auto it = find(word_list.begin(),word_list.end(),search_term);
    return it != word_list.end();
}
int main()
{
    vector<string> word_list = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    string search_term = {"kiwi"};

    bool term = is_word_in_list(word_list,search_term);
    cout << (term ? "True" : "False" );

    return (0);
}