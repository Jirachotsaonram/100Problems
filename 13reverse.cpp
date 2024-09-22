#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverse_string(string &s);
int main(){
    string input;
    cout << "input : " ;
    getline(cin,input);
    string reverse_result = reverse_string(input);
    cout << "Output : " << reverse_result;
    return(0);
}
string reverse_string(string &s){
    string result = s;
    reverse(result.begin(),result.end());
    return result;
}