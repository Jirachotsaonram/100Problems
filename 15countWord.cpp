#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string,int> count_word_occurrences(const vector<string>& words){
    map<string,int> count_word;
    for(const string word : words){
        count_word[word]++;
    }
    return count_word;
}

int main(){
    vector<string> words = {"apple", "banana", "apple", "orange", "banana", "apple"};
    map<string,int> result = count_word_occurrences(words);
    for(const auto& piar : result){
        cout << piar.first << " : " << piar.second;
    }
    return 0 ;
}