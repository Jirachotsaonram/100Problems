#include <iostream>
#include <string>
using namespace std;

string toggle_case(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            // ถ้าเป็นอักษรพิมพ์ใหญ่ ให้เปลี่ยนเป็นพิมพ์เล็ก
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            // ถ้าเป็นอักษรพิมพ์เล็ก ให้เปลี่ยนเป็นพิมพ์ใหญ่
            str[i] = toupper(str[i]);
        }
    }
    return str;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    
    string result = toggle_case(input);
    cout << "Toggled case string: " << result << endl;

    return 0;
}
